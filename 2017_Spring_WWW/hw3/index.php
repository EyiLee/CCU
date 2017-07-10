<?php
	session_start();
	if(!isset($_SESSION["login"]) || ($_SESSION["login"]=="")) {
		$user = false;
	} else {
		$user = true;
	}
?>
<!doctype html>
<html>
	<head>
		<title>Fake Instagram</title>
		<meta charset="utf-8">
		<meta name=viewport content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
	</head>
	<body>
		<nav class="navbar navbar-inverse navbar-fixed-top">
			<div class="container">
				<div class="navbar-header">
					<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
						<span class="sr-only"></span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
					</button>
				</div>
				<div class="navbar-collapse collapse">
					<ul class="nav navbar-nav">
						<li><a href="./">Home</a></li>
					</ul>
					<?php
						if($user) {
					?>
							<ul class="nav navbar-nav navbar-right">
								<li><a href="#"><?= $_SESSION["login"] ?></a></li>
								<li><a href="#post" data-toggle="modal" data-target="#posts">Post</a></li>
								<li><a href="#signout" data-toggle="modal" data-target="#signout">Sign Out</a></li>
							</ul>
					<?php
						} else {
					?>
							<ul class="nav navbar-nav navbar-right">
								<li><a href="#signin" data-toggle="modal" data-target="#signin">Sign In</a></li>
								<li><a href="#signup" data-toggle="modal" data-target="#signup">Sign Up</a></li>
							</ul>
					<?php
						}
					?>
				</div>
			</div>
		</nav>
		<div class="container" style="padding-top:75px;">
			<?php
				if ($_SESSION["sign"] == "signin-fail") {
			?>
				<div class="alert alert-danger" role="alert"><p>Username or Password Wrong!</p></div>
			<?php
				} else if ($_SESSION["sign"] == "signup-fail") {
			?>
				<div class="alert alert-danger" role="alert"><p>Username have been used!</p></div>
			<?php
				} else if ($_SESSION["sign"] == "signup-success") {
			?>
				<div class="alert alert-success" role="alert"><p>Create account success, now you can sign in!</p></div>
			<?php
				}
				unset($_SESSION["sign"]);
				require_once "db.php";
				if(!isset($_GET["page"]) || ($_GET["page"]) == "") {
					$page = 0;
				} else {
					$page = 10 * $_GET["page"];
				}
				$conn = db();
				$stmt = $conn->prepare("select Postz.id, Postz.content, Postz.filepath, Postz.updatetime, Users.username from Postz, Users where Postz.uid = Users.id order by updatetime DESC limit 10 offset :page");
				$stmt->bindParam(":page", $page, PDO::PARAM_INT);
				$stmt->execute();
				$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
				unset($conn);
				foreach($result as $post) {
			?>
				<div class="row">
					<div class="col-sm-6 col-sm-offset-3">
						<div class="thumbnail">
							<img src=<?= $post["filepath"] ?>>
							<div class="caption">
								<h3><?= $post["username"] ?></h3>
								<p><?= $post["content"] ?></p>
								<div>
									<form id="like<?= $post["id"] ?>" action="./like.php" method="POST">
										<input type="hidden" name="pid" value="<?= $post["id"] ?>">									
										<input type="hidden" name="uid" value="<?= $_SESSION["uid"] ?>">
									</form>
									<?php 
										if($user) {
									?>
									<button type="submit" class="btn btn-link" form="like<?= $post["id"] ?>">
									<?php 
										}
									?>
										<?php
											$conn = db();
											$stmt = $conn->prepare("select count(*) from `Like` where pid = :pid and uid = :uid");
											$stmt->bindParam(":pid", $post["id"], PDO::PARAM_INT);
											$stmt->bindParam(":uid", $_SESSION["uid"], PDO::PARAM_INT);
											$stmt->execute();
											$like = $stmt->fetch(PDO::FETCH_ASSOC);
											$stmt = $conn->prepare("select count(*) from `Like` where pid = :pid");
											$stmt->bindParam(":pid", $post["id"], PDO::PARAM_INT);
											$stmt->execute();
											$likes = $stmt->fetch(PDO::FETCH_ASSOC);
											unset($conn);
											if ($like["count(*)"] == "0") {
										?>
											<span style="color:black;" class="glyphicon glyphicon-thumbs-up"></span>
											<span><?= $likes["count(*)"] ?></span>											
										<?php
											} else {
										?>
											<span style="color:red;" class="glyphicon glyphicon-thumbs-up"></span>
											<span><?= $likes["count(*)"] ?></span>
										<?php
											}
										?>
									<?php 
										if($user) {
									?>
									</button>
									<?php 
										}
									?>
									<p class="text-right"><?= $post["updatetime"] ?></p>
								</div>
							</div>
							<div>
								<ul class="list-group">
									<?php
										$conn = db();
										$stmt = $conn->prepare("select Commentzz.content, Commentzz.updatetime, Users.username from Commentzz, Users where Commentzz.pid = :pid and Users.id = Commentzz.uid order by updatetime");
										$stmt->bindParam(":pid", $post["id"], PDO::PARAM_INT);
										$stmt->execute();
										$comment = $stmt->fetchAll(PDO::FETCH_ASSOC);
										unset($conn);
										foreach($comment as $comments) {
									?>
										<li class="list-group-item">
											<h4><?= $comments["username"] ?><h4>
											<p><?= $comments["content"] ?></p>
											<p class="text-right"><?= $comments["updatetime"] ?></p>
										</li>
									<?php
										}
									?>
								</ul>
								<?php 
									if($user) {
								?>
									<div class="row">
										<div class="col-sm-12">
											<div class="input-group">
												<input type="text" name="content" class="form-control" form="com<?= $post["id"] ?>">
												<span class="input-group-btn">
													<button type="submit" class="btn btn-primary" form="com<?= $post["id"] ?>">Submit</button>
												</span>
											</div>

											<form id="com<?= $post["id"] ?>" action="./comment.php" method="POST">
												<input type="hidden" name="uid" value="<?= $_SESSION["uid"] ?>">
												<input type="hidden" name="pid" value="<?= $post["id"] ?>">
											</form>
										</div>
									</div>
								<?php 
									}
								?>
							</div>
						</div>
					</div>
				</div>
			<?php
				}
			?>
		</div>
		<div id="signin" class="modal fade" role="dialog">
			<div class="modal-dialog" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close">
							<span aria-hidden="true">&times;</span>
						</button>
						<h4>Sign In</h4>
					</div>
					<div class="modal-body">
						<form class="form-horizontal" action="./signin.php" method="POST">
							<div class="form-group">
								<label for="signin-username" class="col-sm-12">Username</label>
								<div class="col-sm-12">
									<input type="text" name="username" id="signin-username" class="form-control" placeholder="Username" required></input>
								</div>
							</div>
							<div class="form-group">
								<label for="signin-password" class="col-sm-12">Password</label>
								<div class="col-sm-12">
									<input type="password" name="password" id="signin-password" class="form-control" placeholder="Password" required></input>
								</div>
							</div>
							<button type="submit" class="btn btn-default" data-dismiss="modal">Close</button>
							<button type="submit" class="btn btn-primary">Sign In</button>
						</form>
					</div>
					<div class="modal-footer">
					</div>
				</div>
			</div>
		</div>

		<div id="signup" class="modal fade" role="dialog">
			<div class="modal-dialog" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close">
							<span aria-hidden="true">&times;</span>
						</button>
						<h4>Sign Up</h4>						
					</div>
					<div class="modal-body">
						<form class="form-horizontal" action="./signup.php" method="POST">
							<div class="form-group">
								<label for="signup-username" class="col-sm-12">Username</label>
								<div class="col-sm-12">
									<input type="text" name="username" id="signup-username" class="form-control" placeholder="Username" required></input>
								</div>
							</div>
							<div class="form-group">
								<label for="signup-password" class="col-sm-12">Password</label>
								<div class="col-sm-12">
									<input type="password" name="password" id="signup-password" class="form-control" placeholder="Password" required></input>
								</div>
							</div>
							<div class="form-group">
								<label for="signup-confirm" class="col-sm-12">Confirm Password</label>
								<div class="col-sm-12">
									<input type="password" name="confirm" id="signup-confirm" class="form-control" placeholder="Confirm Password" required></input>
								</div>
							</div>
							<button type="submit" class="btn btn-default" data-dismiss="modal">Close</button>
							<button type="submit" class="btn btn-primary">Sign Up</button>
						</form>
						<script>
							var signupform = document.querySelector("#signup form");

							signupform.addEventListener('submit', function(event) {
								var password = document.querySelector("#signup-password").value;
								var confirm = document.querySelector("#signup-confirm").value;
								if (password == confirm) {
									this.submit();
								} else {
									alert("Make sure you password is correct!");
									event.preventDefault();
								}
							})
						</script>
					</div>
					<div class="modal-footer">
					</div>
				</div>
			</div>
		</div>

		<div id="signout" class="modal fade" role="dialog">
			<div class="modal-dialog" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close">
							<span aria-hidden="true">&times;</span>
						</button>
						<h4>Sign Out</h4>						
					</div>
					<div class="modal-body">
						<p>Are you sure to sign out ?</p>
						<form class="form-horizontal" action="./signout.php" method="POST">
							<button type="submit" class="btn btn-default" data-dismiss="modal">Close</button>
							<button type="submit" class="btn btn-primary">Sure</button>
						</form>
					</div>
				</div>
			</div>
		</div>

		<div id="posts" class="modal fade" role="dialog">
			<div class="modal-dialog" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close">
							<span aria-hidden="true">&times;</span>
						</button>
						<h4>說些什麼吧...?</h4>						
					</div>
					<div class="modal-body">
						<form class="form-horizontal" action="./upload.php" method="POST" enctype="multipart/form-data">
							<div class="form-group">
								<div class="col-sm-12">
									<textarea name="content" style="width:100%;max-width:100%;height:10em;max-height:10em;" required></textarea>
								</div>
							</div>
							<div class="form-group">
								<div class="col-sm-12">
									<input type="file" name="file" id="file" required>
								</div>
							</div>
							<button type="submit" class="btn btn-default" data-dismiss="modal">Close</button>
							<button type="submit" class="btn btn-primary">Submit</button>
							<input type="hidden" name="uid" value="<?= $_SESSION["uid"] ?>">
						</form>
						<script>
							var postsform = document.querySelector("#posts form");

							postsform.addEventListener('submit', function(event) {
								var file = document.querySelector("#file").files[0];
								if (file && file.size > 87040) {
									alert("Image size must less than 1 MB");
									event.preventDefault();
								} else {
									this.submit();
								}
							})
						</script>
					</div>
				</div>
			</div>
		</div>
	</body>
</html>
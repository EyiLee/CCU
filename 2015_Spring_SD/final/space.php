<?php
	session_start();
	require_once "db_config.php";
	
	if(!isset($_SESSION["login"])) {
		$admin = false;
	} else if($_SESSION["login"] == "") {
		$admin = false;
		$login = false;
	} else {
		$admin = true;
		$login = true;
	}
	
	$taglist = ["交通工具","書籍","生活物品","其他"];
	$account = htmlspecialchars($_GET["account"], ENT_QUOTES);
?>
<!doctype html>
<html>
	<head>
		<title>Trade Board</title>
		<meta charset="utf-8">
		<meta name=viewport content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css">
		<link rel="stylesheet" href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/main.css">
	</head>
	<body>
		<div class="container">
			<?php
				require_once "header.php"
			?>
			<div class="row">
				<div class="col-xs-4">
					<span class="thumbnail">
						<img src="sample.jpg" alt="...">
					</span>
					<div class="panel panel-default">
					<!-- Default panel contents -->
						<div class="panel-heading"><?= $account ?>的個人資訊</div>
						<div class="panel-body">
							<p></p>
						</div>

					<!-- List group -->
						<ul class="list-group">
							<li class="list-group-item"></li>
							<li class="list-group-item"></li>
							<li class="list-group-item"></li>
							<li class="list-group-item"></li>
						</ul>
					</div>
				</div>
				<div class="col-xs-8">
					<div class="panel panel-default">
						<div class="panel-heading">通知</div>
						<?php
							$conn = connDB();
							$stmt = $conn->prepare("select pid from Product where account like :account");
							$stmt->bindParam(":account", $account);
							$stmt->execute();
							$pids = $stmt->fetchAll(PDO::FETCH_ASSOC);
							
							$conn = null;
							
							foreach($pids as $pid) {
								$conn = connDB();
								$stmt = $conn->prepare("select * from PostMsg where pid in (select pid from Product where account like :account)");
								$stmt->bindParam(":account", $account);
								$stmt->execute();
								$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
						?>
									<ul class="list-group">
						<?php
										foreach($result as $msg) {
						?>
											<li class="list-group-item product-header">
												<a class="title" href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/product.php?pid=<?= $msg['pid'] ?>"><?= $msg["content"] ?></a>
												<span class="title">by <?= $msg['account'] ?></span>
												<span class="updatetime"><?= $msg["updatetime"] ?></span>
												<span class="account"><?= $msg["account"] ?></span>
											</li>
						<?php
									}
						?>
									</ul>
						<?php
							}
						?>
					</div>
					<div class="panel panel-default">
						<div class="panel-heading">
							<?php
								if($_SESSION["login"] == $account) {
									echo "你的拍賣";
								} else {
									echo "他的拍賣";
								}
							?>
						</div>
						<?php
							$conn = connDB();
							$stmt = $conn->prepare("select distinct * from Product where account like :account order by updatetime DESC");
							$stmt->bindParam(":account", $account);
							$stmt->execute();
							$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
							
							$conn = null;
						?>
							<ul class="list-group">
						<?php
							foreach($result as $product) {
						?>
								<li class="list-group-item product-header">
									<a class="title" href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/product.php?pid=<?= $product['pid'] ?>"><?= $product["title"] ?></a>
									<span class="updatetime"><?= $product["updatetime"] ?></span>
									<span class="account"><?= $product["account"] ?></span>
								</li>
						<?php
							}
						?>
							</ul>
					</div>
				</div>
			</div>
			<footer>
				<p>By Eyi , AUDO</p>
			</footer>
		</div>
		<?php
			require_once "dialog.php";
		?>
	</body>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
</html>
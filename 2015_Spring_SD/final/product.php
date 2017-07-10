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
				</div>
				<div class="col-xs-8">
					<?php
						$pid = htmlspecialchars($_GET["pid"], ENT_QUOTES);
						
						$conn = connDB();
						$stmt = $conn->prepare("select * from Product where pid = :pid");
						$stmt->bindParam(":pid", $pid);
						$stmt->execute();
						$result = $stmt->fetch(PDO::FETCH_ASSOC);
						
						$conn = null;
					?>
					<div class="panel panel-default">
					<!-- Default panel contents -->
						<div class="panel-heading"><?= $result["title"] ?></div>
						<div class="panel-body">
							<p><?= $result["content"] ?></p>
						</div>

					<!-- List group -->
						<ul class="list-group">
							<li class="list-group-item">聯絡方式: <?= $result["connection"] ?></li>
							<li class="list-group-item">買/賣家: <a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/space.php?account=<?= $result['account'] ?>"><?= $result["account"] ?></a></li>
							<li class="list-group-item">分類: <?= $taglist[$result["tag"]] ?></li>
							<li class="list-group-item">
								<button type="button" class="btn btn-default navbar-btn" data-toggle="modal" data-target="#post-product-msg">留言給買/賣家</button>
							</li>
						</ul>
					</div>
					
					<div class="panel panel-default">
						<div class="panel-heading">相關留言</div>
						<?php
							$pid = htmlspecialchars($_GET["pid"], ENT_QUOTES);
							
							$conn = connDB();
							$stmt = $conn->prepare("select count(*) from PostMsg where pid = :pid");
							$stmt->bindParam(":pid", $pid);
							$stmt->execute();
							$result = $stmt->fetch(PDO::FETCH_ASSOC);
							
							$conn = null;
							
							if($result["count(*)"] > 0) {
								$conn = connDB();
								$stmt = $conn->prepare("select * from PostMsg where pid = :pid");
								$stmt->bindParam(":pid", $pid);
								$stmt->execute();
								$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
						?>
									<ul class="list-group">
						<?php
										foreach($result as $msg) {
						?>
											<li class="list-group-item product-header">
												<span class="title"><?= $msg["content"] ?></span>
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
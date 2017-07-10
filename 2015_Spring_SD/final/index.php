<?php
	session_start();
	
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
					<div class="list-group">
						<span class="list-group-item list-group-item-info">分類清單</span>
						<a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php?tag=0" class="list-group-item">交通工具</a>
						<a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php?tag=1" class="list-group-item">書籍</a>
						<a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php?tag=2" class="list-group-item">生活物品</a>
						<a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php?tag=3" class="list-group-item">其他</a>
					</div>
				</div>
				<div class="col-xs-8">
					<div class="panel panel-default">
						<div class="panel-heading">
							<h3 class="panel-title">大家在賣什麼
								<?php
									if(isset($_GET["tag"])) {
										echo "　/　" . $taglist[$_GET["tag"]];
									}
								?>
							</h3>
						</div>
						<div class="panel-body">
							<?php
								require_once "show_buys.php";
							?>
						</div>
					</div>
					<div class="panel panel-default">
						<div class="panel-heading">
							<h3 class="panel-title">大家想買什麼
								<?php
									if(isset($_GET["tag"])) {
										echo "　/　" . $taglist[$_GET["tag"]];
									}
								?>
							</h3>
						</div>
						<div class="panel-body">
							<?php
								require_once "show_sells.php";
							?>
						</div>
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
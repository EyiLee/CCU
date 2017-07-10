<?php
	session_start();
	if(!isset($_SESSION["login"]) || ($_SESSION["login"]=="")) {
		header("refresh:3; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
		echo "<meta charset='utf-8'>";
		echo "請先登入帳號，3秒後返回首頁";
		exit;
	} else {
		$admin = true;
	}
	
	require_once "db_config.php";
	
	if(isset($_POST["edit"]) && $_POST["edit"] == "true") {
		$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
		$content = htmlspecialchars($_POST["content"], ENT_QUOTES);

		$conn = connDB();
		$stmt = $conn->prepare("update Post	set content=:content where pid = :pid");
		$stmt->bindParam(":content",$content);
		$stmt->bindParam(":pid",$pid);
		$stmt->execute();
		$conn = null;
		
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
		exit;
	} else {
		$pid = htmlspecialchars($_GET["pid"], ENT_QUOTES);
	}
?>
<!doctype html>
<html>
	<head>
		<title>Simple Message Board</title>
		<meta charset="utf-8">
		<meta name=viewport content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="main.css">
	</head>
	<body>
		<header>
			<a href="./index.php">首頁</a>
			<form class="search" action="<?= $_SERVER['PHP_SELF'] ?>" method="GET">
				<input type="search" name="keyword" placeholder="Search...">
				<input type="submit" value="搜尋">
			</form>
			<?php
				if($admin) {
			?>
					<form class="logout" action="./logout.php" method="GET">
						<input type="submit" value="登出">
					</form>
			<?php
				} else {
			?>
					<form class="login" action="./login.php" method="POST">
						<input type="text" name="account" placeholder="Account" required>
						<input type="password" name="password" placeholder="Password" required>
						<input type="submit" value="登入">
					</form>
					<div class="register">
						<button onClick="showreg()">註冊</button>
					</div>
			<?php
				}
				if($admin) {
			?>
					<div class="member">
						Hi <?= $_SESSION["login"] ?>
					</div>
			<?
				}
			?>
		</header>
		
		<section id="reg" style="display:none;">
			<form action="./register.php" method="POST">
				<input type="text" name="name" placeholder="Name" required>
				<input type="text" name="account" placeholder="Account" required>
				<input type="password" name="password" placeholder="Password" required>
				<input type="password" name="confirm" placeholder="Confirm Password" required>
				<input type="email" name="email" placeholder="Email" required>
				<input type="submit" value="註冊">
			</form>
			<button onClick="closereg()">取消</button>
		</section>
		
		<?php
			$conn = connDB();
			$stmt = $conn->prepare("select * from Post where pid = :pid");
			$stmt->bindParam(":pid", $pid);
			$stmt->execute();
			$post = $stmt->fetch(PDO::FETCH_ASSOC);
			$conn = null;
		?>
		
		<div id="main">
			<section class="posts">
				<div class="article">
					<span class="account"><?= $post["account"] ?></span>
					<?php
						if($post["account"] == $_SESSION["login"]) {
					?>
							<div class="edit">
								<input onClick="sendedit('<?= 'com-' . $post['pid'] ?>')" type="button" value="儲存">
							</div>
					<?php
						}
					?>
					<form id="<?= 'com-' . $post['pid'] ?>" action="<?= $_SERVER['PHP_SELF'] ?>" method="POST">
						<textarea name="content"><?= $post["content"] ?></textarea>
						<input type="hidden" name="pid" value="<?= $post['pid'] ?>">
						<input type="hidden" name="edit" value="true">
					</form>
					<p class="updatetime"><?= $post["updatetime"] ?></p>
				</div>
			</section>
		</div>
	</body>
	<script>
		function sendedit(id) {
			document.getElementById(id).submit();
		}
	</script>
</html>
<?php
	session_start();
	if(!isset($_SESSION["login"]) || ($_SESSION["login"]=="")) {
		$admin=false;
	} else {
		$admin=true;
	}
	
	$keyword = htmlspecialchars($_GET["keyword"], ENT_QUOTES);
	
	require_once "db_config.php";
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
			<form class="search" action="./search.php" method="GET">
				<input type="search" name="keyword" placeholder="<?= $keyword ?>">
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
			<form id="reg" style="display:none;" action="./register.php" method="POST">
				<input type="text" name="name" placeholder="Name" required>
				<input type="text" name="account" placeholder="Account" required>
				<input type="password" name="password" placeholder="Password" required>
				<input type="password" name="confirm" placeholder="Confirm Password" required>
				<input type="email" name="email" placeholder="Email" required>
				<input type="submit" value="註冊">
				<input type="button" value="取消" onClick="closereg()">
			</form>
		</header>
		
		<div id="main">
			<?php
				$keyword = "%".$keyword."%";

				$conn = connDB();
				$stmt = $conn->prepare("select * from Post where content like :keyword order by updatetime DESC limit 10");
				$stmt->bindParam(":keyword", $keyword);
				$stmt->execute();
				$post = $stmt->fetchAll(PDO::FETCH_ASSOC);
				$conn = null;

				foreach($post as $pdata) {
			?>
					<section class="posts">
						<div class="article">
							<span class="account"><?= $pdata["account"] ?></span>
							<?php
								if($pdata["account"] == $_SESSION["login"]) {
							?>
									<div class="edit">
										<form action="./edit.php" method="GET">
											<input type="submit" value="修改">
											<input type="hidden" name="pid" value="<?= $pdata["pid"] ?>">
										</form>
									</div>
									<div class="delete">
										<form onsubmit="return confirm('是否刪除貼文與檔案?')" action="./delete.php" method="POST">
											<input type="submit" value="刪除">
											<input type="hidden" name="pid" value="<?= $pdata["pid"] ?>">
											<input type="hidden" name="account" value="<?= $pdata["account"] ?>">
										</form>
									</div>
							<?php
								}
							?>
							<p><?= $pdata["content"] ?></p>
							<p class="updatetime"><?= $pdata["updatetime"] ?></p>
							<?php
								if($pdata["filepath"] !== "") {
							?>
									<a href="<?= './download.php?pid=' . $pdata["pid"] ?>"><?= $pdata["filename"] ?></a>
							<?php
								}
								$conn = connDB();
								$stmt = $conn->prepare("select * from Comment where pid = :pid order by updatetime");
								$pid = $pdata["pid"];
								$stmt->bindParam(":pid", $pid);
								$stmt->execute();
								$comment = $stmt->fetchAll(PDO::FETCH_ASSOC);
								$conn = null;
							?>
						</div>
						<ul id="<?= 'ul-com-' . $pdata['pid'] ?>" class="ul-com">
							<?php
								foreach($comment as $cdata) {
							?>
									<li>
										<p class="account"><?= $cdata["account"] ?></p>
										<p class="content"><?= $cdata["content"] ?></p>
										<p class="updatetime"><?= $cdata['updatetime'] ?></p>
									</li>
							<?php
								}
							?>
						</ul>
						<?php
							if($admin) {
						?>
								<div class="comment">
									<form id="<?= 'com-' . $pdata['pid'] ?>" onsubmit="return sendcomment('<?= 'com-' . $pdata['pid'] ?>')">
										<textarea name="content" rows="1" style="resize:none;" placeholder="回覆留言...?"></textarea>
										<input type="submit" value="送出">
										<input type="hidden" name="account" value="<?= $_SESSION["login"] ?>">
										<input type="hidden" name="pid" value="<?= $pdata['pid'] ?>">
									</form>
								</div>
						<?php
							}
						?>
					</section>
			<?php
				}
			?>
		<div>
	</body>
	<script>
		function showreg() {
			document.getElementById("reg").style.display = "inline-block";
		}
		function closereg() {
			document.getElementById("reg").style.display = "none";
		}
	</script>
</html>
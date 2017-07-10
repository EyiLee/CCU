<?php
	require_once "contacts_config.php";
	require_once "uri_config.php";
	if( !isset($_GET["page"]) ) {
		$_GET["page"] = 1;
	}
	$page = $_GET["page"];
	$result = get_contacts();
	unset($_GET["sort"]);
	unset($_GET["page"]);
	$URI = reset_URI();
?>
<!doctype html>
<html>
	<head>
		<meta charset="utf-8">
		<title>電腦軟體設計 - 通訊錄</title>
		<link rel="icon" href="correct.png" type="image/png" sizes="32x32">
		<link rel="stylesheet" href="main.css">
		<script src="main.js"></script>
	</head>
	<body>
		<header>
			<a href="/~lchb102u/hw2" class="portrait"></a>
			<h1>通訊錄</h1>
			<form class="searchpad"action="<?= $_SERVER['PHP_SELF'] ?>" method="GET">
				<input type="search" name="keyword" placeholder="搜尋...">
				<input type="submit">
			</form>
		</header>
		<section class="main">
			<section class="contain">
				<table class="contactspad">
					<caption>聯絡人</caption>
					<tr>
						<th><a href="<?= $URI.'sort=name' ?>">姓名</a></th>
						<th><a href="<?= $URI.'sort=email' ?>">E-mail</a></th>
						<th><a href="<?= $URI.'sort=phone' ?>">電話</a></th>
						<th>詳細資料</th>
						<th>編輯</th>
						<th>刪除</th>
					</tr>
					<?php
						$size = count($result);
						$index = ($page - 1) * 5;
						for($i = 0; $i < 5; $i++) {
							if( $index + $i >= $size) {
								break;
							}
							$row = $result[$index+$i];
					?>
							<tr>
								<td><?= $row["name"] ?></td>
								<td><?= $row["email"] ?></td>
								<td><?= $row["phone"] ?></td>
								<td>
									<form action="contacts_detail.php" method="GET">
										<input type="hidden" name="select" value="<?= $row['email'] ?>">
										<input type="submit" value="詳細">
									</form>
								</td>
								<td>
									<form action="contacts_edit.php" method="GET">
										<input type="hidden" name="select" value="<?= $row['email'] ?>">
										<input type="submit" value="編輯">
									</form>
								</td>
								<td>
									<form action="<?= $_SERVER['PHP_SELF'] ?>" method="POST">
										<input type="hidden" name="delete" value="<?= $row['email'] ?>">
										<input type="submit" value="刪除">
									</form>
								</td>
							</tr>
					<?php
						}
					?>
				</table>
				<section class="render">
					<?php
						$size_p = ($size - ($size % 5)) / 5;
						if($size % 5 != 0) {
							$size_p++;
						}
						for($i = 1; $i <= $size_p; $i++) {
							echo "<a class='btn' href=" . $URI . "page=" . $i . ">$i</a>";
						}
					?>
					<a class="btn contactsadd" href="contacts_add.php">新增</a>
				</section>
			</section>
		</section>
		<footer>
			<section class="info">
				<section>
					<span>課程：電腦軟體設計 製作</span><br>
					<span>學生：李佳祥</span><br>
					<span><small>Copyright©國立中正大學資訊工程學系</small></span>
				</section>
				<section class="infolinks">
					｜ <a href="http://www.cs.ccu.edu.tw" target="_blank">中正資工</a> ｜ <a href="http://bach.ccu.edu.tw/tools/page/show_page.php?page_url=/Site/softwaredesign/" target="_blank">課程網頁</a> ｜ 授課教師：吳昇老師
				</section>
			</section>
		</footer>
	</body>
</html>

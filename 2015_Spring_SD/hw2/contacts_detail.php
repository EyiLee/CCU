<?php
	require_once "contacts_config.php";
	$result = get_contacts();
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
			<h1>詳細資料</h1>
		</header>
		<section class="main">
			<section class="contain">
				<table class="contactspad">
					<caption><?= $result["name"] ?></caption>
					<tr>
						<th>Name</th>
						<td><?= $result["name"] ?></td>
					</tr>
					<tr>
						<th>Gender</th>
						<td><?= $result["gender"] ?></td>
					</tr>
					<tr>
						<th>Phone</th>
						<td><?= $result["phone"] ?></td>
					</tr>
					<tr>
						<th>Email</th>
						<td><?= $result["email"] ?></td>
					</tr>
					<tr>
						<th>Birthday</th>
						<td><?= $result["year"]."-".$result["month"]."-".$result["day"] ?></td>
					</tr>
					<tr>
						<th>Address</th>
						<td><?= $result["address"] ?></td>
					</tr>
				</table>
				<section class="render">
					<input type="button" onclick="goBack();" value="回上一頁">
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
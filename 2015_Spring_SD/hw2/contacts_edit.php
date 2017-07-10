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
			<h1>更新聯絡人資料</h1>
			<form class="searchpad"action="/~lchb102u/hw2" method="GET">
				<input type="search" name="keyword" placeholder="搜尋...">
				<input type="submit">
			</form>
		</header>
		<section class="main">
			<section class="contain">
				<form class="addpad" action="<?= $_SERVER['PHP_SELF'] ?>" method="POST">
					<div class="inputgroup">
						<label for="name">姓名</label>
						<input type="text" id="name" name="name" value="<?= $result["name"] ?>" placeholder="姓氏與名字" required>
					</div>
					<div class="inputgroup">
						<label for="email">Email</label>
						<input type="email" id="email" name="email" value="<?= $result["email"] ?>" placeholder="example@domain.com" required>
					</div>
					<div class="inputgroup">
						<label for="phone">電話</label>
						<input type="tel" id="phone" name="phone" value="<?= $result["phone"] ?>" placeholder="0900123456" required>
					</div>
					<div class="inputgroup">
						<label>性別</label>
						<label for="male">男</label>
						<input type="radio" id="male" name="gender" value="male" required <?php if( !strcmp($result["gender"],"male") ) { echo "checked"; } ?>>
						<label for="female">女</label>
						<input type="radio" id="female" name="gender" value="female" required <?php if( !strcmp($result["gender"],"female") ) { echo "checked"; } ?>>
					</div>
					<div class="inputgroup">
						<label>生日(年/月/日)</label>
						<select name="year">
							<?php
								for($i = 2015; $i >= 1915 ; $i--) {
									echo "<option value=" . $i;
									if( intval($result["year"]) == $i) {
										echo " selected";
									}
									echo ">" . $i . "</option>";
								}
							?>
						</select>
						<select name="month">
							<?php
								for($i = 1; $i <= 12 ; $i++) {
									echo "<option value=" . $i;
									if( intval($result["month"]) == $i) {
										echo " selected";
									}
									echo ">" . $i . "</option>";
								}
							?>
						</select>
						<select name="day">
							<?php
								for($i = 1; $i <= 31 ; $i++) {
									echo "<option value=" . $i;
									if( intval($result["day"]) == $i) {
										echo " selected";
									}
									echo ">" . $i . "</option>";
								}
							?>
						</select>
					</div>
					<div class="inputgroup">
						<label for="address">地址</label>
						<input type="text" id="address" name="address" value="<?= $result["address"] ?>" placeholder="你的地址" required>
					</div>
					<input type="hidden" name="select" value="<?= $_GET["select"] ?>">
					<input type="hidden" name="edit" value="true">
					<div class="inputgroup inputgroup_center">
						<input type="submit" value="送出">
						<input type="reset" value="重設">
						<input type="button" onClick="goBack();" value="回上一頁">
					</div>
				</form>
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
	<body>
</html>
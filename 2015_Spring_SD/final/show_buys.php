<?php
	require_once "db_config.php";

	if(isset($_GET["tag"])) {
		$tag = htmlspecialchars($_GET["tag"], ENT_QUOTES);
		
		$conn = connDB();
		$stmt = $conn->prepare("select * from Product where type = '0' and tag = :tag order by updatetime DESC limit 10");
		$stmt->bindParam(":tag", $tag);
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		
		$conn = null;
	} else {
		$conn = connDB();
		$stmt = $conn->prepare("select * from Product where type = '0' order by updatetime DESC limit 10");
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		
		$conn = null;
	}
	
	echo "<ul class='list-group'>";
	
	$taglist = ["交通工具","書籍","生活物品","其他"];
	
	foreach($result as $buys) {
		echo "<li class='list-group-item product-header'>";
			echo "<span class='tag'>[" . $taglist[$buys["tag"]] . "]</span>";
			echo "<a class='title' href='http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/product.php?pid=" . $buys["pid"] . "'>" . $buys["title"] . "</a>";
			echo "<span class='updatetime'>" . $buys["updatetime"] . "</span>";
			echo "<span class='account'>" . $buys["account"] . "</span>";
		echo "</li>";
	}
	
	echo "</ul>";
?>
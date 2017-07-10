<?php
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	$title = htmlspecialchars($_POST["title"], ENT_QUOTES);
	$content = htmlspecialchars($_POST["content"], ENT_QUOTES);
	$connection = htmlspecialchars($_POST["connection"], ENT_QUOTES);
	$tag = htmlspecialchars($_POST["tag"], ENT_QUOTES);
	$type = htmlspecialchars($_POST["type"], ENT_QUOTES);

	require_once "db_config.php";
	
	$conn = connDB();
	$stmt = $conn->prepare("insert into Product (account, title, content, connection, tag, type) values (:account, :title, :content, :connection, :tag, :type)");
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":title", $title);
	$stmt->bindParam(":content", $content);
	$stmt->bindParam(":connection", $connection);
	$stmt->bindParam(":tag", $tag);
	$stmt->bindParam(":type", $type);
	$stmt->execute();
	
	$conn = null;
	
	header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
	exit;
?>
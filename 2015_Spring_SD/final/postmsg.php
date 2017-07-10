<?php
	require_once "db_config.php";
	
	$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	$content = htmlspecialchars($_POST["content"], ENT_QUOTES);
	
	if($content == "") {
		header("Location: http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/product.php?pid=$pid");
		exit;
	}
	
	$conn = connDB();
	$stmt = $conn->prepare("insert into PostMsg (pid, account, content) values (:pid, :account, :content)");
	$stmt->bindParam(":pid", $pid);
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":content", $content);
	$stmt->execute();
	
	$conn = null;
	header("Location: http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/product.php?pid=$pid");
	exit;
?>
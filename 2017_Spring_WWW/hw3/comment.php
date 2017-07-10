<?php
	require_once "db.php";
	
	$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
	$uid = htmlspecialchars($_POST["uid"], ENT_QUOTES);
	$content = htmlspecialchars($_POST["content"], ENT_QUOTES);
	
	if($content == "") {
		exit;
	}
	
	$conn = db();
	$stmt = $conn->prepare("insert into Commentzz (pid, uid, content) values (:pid, :uid, :content)");
	$stmt->bindParam(":pid", $pid);
	$stmt->bindParam(":uid", $uid);
	$stmt->bindParam(":content", $content);
	$stmt->execute();
	
	unset($conn);

	header("refresh:0; url=./index.php");
	exit;
?>
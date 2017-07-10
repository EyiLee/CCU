<?php
	require_once "db_config.php";
	
	$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	$content = htmlspecialchars($_POST["content"], ENT_QUOTES);
	
	if($content == "") {
		exit;
	}
	
	$conn = connDB();
	$stmt = $conn->prepare("insert into Comment (pid, account, content) values (:pid, :account, :content)");
	$stmt->bindParam(":pid", $pid);
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":content", $content);
	$stmt->execute();
	
	$conn = null;
?>
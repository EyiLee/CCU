<?php
	session_start();
	
	$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	
	if(!isset($_SESSION["login"]) || ($_SESSION["login"]=="")) {
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
		exit;
	} else if($_SESSION["login"] !== $_POST["account"]) {
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
		exit;
	} else {
		require_once "db_config.php";
		
		$conn = connDB();
		$stmt = $conn->prepare("select filepath from Post where pid = :pid");
		$stmt->bindParam(":pid", $pid);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		
		$conn = null;
		
		$filepath = $result["filepath"];
		unlink($filepath);
		
		$conn = connDB();
		$stmt = $conn->prepare("delete from Post where pid = :pid");
		$stmt->bindParam(":pid",$pid);
		$stmt->execute();
		
		$conn = null;
		
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
		exit;
	}
?>
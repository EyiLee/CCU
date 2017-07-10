<?php
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	$password = htmlspecialchars($_POST["password"], ENT_QUOTES);
	$shapassword = hash("sha512", $password);
	
	require_once "db_config.php";

	$conn = connDB();
	$stmt = $conn->prepare("select password from Account where account like :account");
	$stmt->bindParam(":account", $account);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);

	$conn = null;

	if($shapassword == $result["password"] && $password !== "") {
		session_start();
		$_SESSION["login"] = $account;
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
		exit;
	} else {
		$_SESSION["login"] = "";
		header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
		exit;
	}
?>
<?php
	$username = htmlspecialchars($_POST["username"], ENT_QUOTES);
	$password = htmlspecialchars($_POST["password"], ENT_QUOTES);
	$confirm = htmlspecialchars($_POST["confirm"], ENT_QUOTES);

	$shapassword = hash("sha512", $password);
	$shaconfirm = hash("sha512", $confirm);

	require_once "db.php";
	
	$conn = db();
	$stmt = $conn->prepare("select count(*) from Users where username like :username");
	$stmt->bindParam(":username", $username);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);
	
	if ($result["count(*)"] !== "0") {
		$_SESSION["sign"] = "signup-fail";
		session_start();
		header("refresh:3; url=./index.php");
		exit;
	}
	
	$stmt = $conn->prepare("insert into Users (username, password) values (:username, :password)");
	$stmt->bindParam(":username", $username);
	$stmt->bindParam(":password", $shapassword);
	$stmt->execute();
	
	unset($conn);
	
	session_start();
	$_SESSION["sign"] = "signup-success";
	header("refresh:0; url=./index.php");
	exit;

?>
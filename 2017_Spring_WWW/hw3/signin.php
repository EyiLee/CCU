<?php
	$username = htmlspecialchars($_POST["username"], ENT_QUOTES);
	$password = htmlspecialchars($_POST["password"], ENT_QUOTES);
	$shapassword = hash("sha512", $password);
	
	require_once "db.php";

	$conn = db();
	$stmt = $conn->prepare("select id, password from Users where username like :username");
	$stmt->bindParam(":username", $username);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);

	unset($conn);

	if($shapassword == $result["password"] && $password !== "") {
		session_start();
		$_SESSION["uid"] = $result["id"];
		$_SESSION["login"] = $username;
		$_SESSION["sign"] = "";
		header("refresh:0; url=./index.php");
		exit;
	} else {
		session_start();
		$_SESSION["sign"] = "signin-fail";
		header("refresh:0; url=./index.php");
		exit;
	}
?>
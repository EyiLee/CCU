<?php
	$name = htmlspecialchars($_POST["name"], ENT_QUOTES);
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
	$password = htmlspecialchars($_POST["password"], ENT_QUOTES);
	$confirm = htmlspecialchars($_POST["confirm"], ENT_QUOTES);
	$email = htmlspecialchars($_POST["email"], ENT_QUOTES);

	$shapassword = hash("sha512", $password);
	$shaconfirm = hash("sha512", $confirm);
	
	if($shapassword !== $shaconfirm) {
		header("refresh:3; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
		echo "<meta charset='utf-8'>";
		echo "密碼錯誤，請重新註冊";
		exit;
	}
	
	require_once "db_config.php";
	
	$conn = connDB();
	$stmt = $conn->prepare("select count(*) from Account where account like :account or email like :email");
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":email", $email);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);
	
	if($result["count(*)"] !== "0") {
		header("refresh:3; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
		echo "<meta charset='utf-8'>";
		echo "帳號或信箱已被人使用，請重新註冊";
		exit;
	}
	
	$stmt = $conn->prepare("insert into Account (name, account, password, email) values (:name, :account, :password, :email)");
	$stmt->bindParam(":name", $name);
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":password", $shapassword);
	$stmt->bindParam(":email", $email);
	$stmt->execute();
	
	$conn = null;
	
	header("refresh:3; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
	echo "<meta charset='utf-8'>";
	echo "帳號已成功申請，3秒後將返回首頁";
	exit;

?>
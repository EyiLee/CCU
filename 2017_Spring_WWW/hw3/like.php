<?php
	require_once "db.php";
	
	$pid = htmlspecialchars($_POST["pid"], ENT_QUOTES);
	$uid = htmlspecialchars($_POST["uid"], ENT_QUOTES);
	
	$conn = db();
	$stmt = $conn->prepare("select count(*) from `Like` where pid = :pid and uid = :uid");
	$stmt->bindParam(":pid", $pid, PDO::PARAM_INT);
	$stmt->bindParam(":uid", $uid, PDO::PARAM_INT);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);

	if ($result["count(*)"] == "0") {
		$stmt = $conn->prepare("insert into `Like` (pid, uid) values (:pid, :uid)");
		$stmt->bindParam(":pid", $pid, PDO::PARAM_INT);
		$stmt->bindParam(":uid", $uid, PDO::PARAM_INT);
		$stmt->execute();
	} else {
		$conn = db();
		$stmt = $conn->prepare("delete from `Like` where pid = :pid and uid = :uid");
		$stmt->bindParam(":pid", $pid, PDO::PARAM_INT);
		$stmt->bindParam(":uid", $uid, PDO::PARAM_INT);
		$stmt->execute();
	}

	unset($conn);

	header("refresh:0; url=./index.php");
	exit;
?>
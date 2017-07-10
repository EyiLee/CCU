<?php
	require_once "db_config.php";
	
	$pid = htmlspecialchars($_GET["pid"], ENT_QUOTES);
	
	$conn = connDB();
	$stmt = $conn->prepare("select filepath from Post where pid = :pid ");
	$stmt->bindParam(":pid", $pid);
	$stmt->execute();
	$result = $stmt->fetch(PDO::FETCH_ASSOC);
	
	if($result["filepath"] == "") {
		exit;
	}
	
	$filename = basename($result["filepath"]);
	$filepath = $result["filepath"];
	$filesize = filesize($filepath);
	header('Pragma: public');
	header('Expires: 0');
	header('Last-Modified: ' . gmdate('D, d M Y H:i ') . ' GMT');
	header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
	header('Cache-Control: private', false);
	header('Content-Type: application/octet-stream');
	header('Content-Length: ' . $filesize);
	header('Content-Disposition: attachment; filename="' . $filename . '";');
	header('Content-Transfer-Encoding: binary');
	readfile($filepath);
?>
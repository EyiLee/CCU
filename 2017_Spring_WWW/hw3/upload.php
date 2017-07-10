<?php
	$uid = htmlspecialchars($_POST["uid"], ENT_QUOTES);
	$content = htmlspecialchars($_POST["content"], ENT_QUOTES);
	$filename = "";
	$filepath = "";
	
	if(isset($_FILES["file"]) && $_FILES["file"]["error"] == "0") {
		$filename = basename($_FILES["file"]["name"]);
		$filedir = "./upload/";
		$fileext = "." . pathinfo($_FILES["file"]["name"], PATHINFO_EXTENSION);
		do {
			$filepath = $filedir . md5(uniqid(rand())) . $fileext;
		} while(file_exists($filepath));
		
		if(!move_uploaded_file($_FILES["file"]["tmp_name"], $filepath)) {
			header("refresh:3; url=./index.php");
			echo "<meta charset='utf-8'>";
			echo "檔案上傳失敗";
			exit;
		}
	}

	$filename = htmlspecialchars($filename, ENT_QUOTES);
	$filepath = htmlspecialchars($filepath, ENT_QUOTES);
	
	require_once "db.php";
	
	$conn = db();
	$stmt = $conn->prepare("insert into Postz (uid, content, filename, filepath) values (:uid, :content, :filename, :filepath)");
	$stmt->bindParam(":uid", $uid);
	$stmt->bindParam(":content", $content);
	$stmt->bindParam(":filename", $filename);
	$stmt->bindParam(":filepath", $filepath);
	$stmt->execute();
	
	unset($conn);
	
	header("refresh:0; url=./index.php");
	exit;
?>
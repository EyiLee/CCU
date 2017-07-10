<?php
	$account = htmlspecialchars($_POST["account"], ENT_QUOTES);
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
			header("refresh:3; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
			echo "<meta charset='utf-8'>";
			echo "檔案上傳失敗";
			exit;
		}
	}

	$filename = htmlspecialchars($filename, ENT_QUOTES);
	$filepath = htmlspecialchars($filepath, ENT_QUOTES);
	
	require_once "db_config.php";
	
	$conn = connDB();
	$stmt = $conn->prepare("insert into Post (account, content, filename, filepath) values (:account, :content, :filename, :filepath)");
	$stmt->bindParam(":account", $account);
	$stmt->bindParam(":content", $content);
	$stmt->bindParam(":filename", $filename);
	$stmt->bindParam(":filepath", $filepath);
	$stmt->execute();
	
	$conn = null;
	
	header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/hw3/index.php");
	exit;
?>
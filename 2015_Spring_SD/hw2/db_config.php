<?php
	function connDB(){
		$servername = "mysql.cs.ccu.edu.tw";
		$username = "lchb102u";
		$password = "hello9002";
		$database = "lchb102u_db";

		try {
			$conn = new PDO("mysql:host=$servername;dbname=$database", $username, $password);
			// set the PDO error mode to exception
			$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		}
		catch(PDOException $exception) {
			echo "Connection failed: " . $exception->getMessage();
		}
		
		return $conn;
	}
?> 

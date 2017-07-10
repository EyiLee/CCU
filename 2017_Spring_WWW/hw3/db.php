<?php
	function db(){
		$servername = "localhost";
		$username = "s402410078";
		$password = "s402410078";
		$database = "s402410078";

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
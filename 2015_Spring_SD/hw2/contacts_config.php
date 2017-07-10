<?php
	require_once "db_config.php";
	
	if( isset($_POST["add"]) ) {
		add_contacts();
	}
	
	if( isset($_POST["edit"]) ) {
		edit_contacts();
	}
	
	if( isset($_POST["delete"]) ) {
		delete_contacts();
	}
	
	function get_contacts() {
		
		if( isset($_GET["keyword"]) ) {
			$keyword = "%" . $_GET["keyword"] . "%";
		}
		if( !isset($_GET["sort"]) ) {
			$_GET["sort"] = "name";
		}

		$select = $_GET["select"];
		$keyword = "%";
		$sort = $_GET["sort"];
		
		try {
			if( isset($_GET["select"]) ) {
				$conn = connDB();
				$stmt = $conn->prepare("select * from Contacts where email like :select");
				$stmt->bindParam(":select",$select);
				$stmt->execute();
				$conn = null;
				
				$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
				return $result[0];
			} else {
				$conn = connDB();
				$stmt = $conn->prepare("select * from Contacts where
					name like :keyword
					or gender like :keyword
					or phone like :keyword
					or email like :keyword
					or year like :keyword
					or month like :keyword
					or day like :keyword
					or address like :keyword
					order by $sort");
				$stmt->bindParam(":keyword",$keyword);
				$stmt->execute();
				$conn = null;
				
				$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
				return $result;
			}
		}
		catch(PDOException $exception) {
			echo "Connection failed: " . $exception->getMessage();
		}
	}
	
	function add_contacts() {
		try {
			$name = htmlspecialchars($_POST["name"],ENT_QUOTES);
			$gender = htmlspecialchars($_POST["gender"],ENT_QUOTES);
			$phone = htmlspecialchars($_POST["phone"],ENT_QUOTES);
			$email = htmlspecialchars($_POST["email"],ENT_QUOTES);
			$year = htmlspecialchars($_POST["year"],ENT_QUOTES);
			$month = htmlspecialchars($_POST["month"],ENT_QUOTES);
			$day = htmlspecialchars($_POST["day"],ENT_QUOTES);
			$address = htmlspecialchars($_POST["address"],ENT_QUOTES);
			
			$conn = connDB();
			$stmt = $conn->prepare("insert into Contacts
			(name, gender, phone, email, year, month, day, address)
			values (:name, :gender, :phone, :email, :year, :month, :day, :address)");
			$stmt->bindParam(":name",$name);
			$stmt->bindParam(":gender",$gender);
			$stmt->bindParam(":phone",$phone);
			$stmt->bindParam(":email",$email);
			$stmt->bindParam(":year",$year);
			$stmt->bindParam(":month",$month);
			$stmt->bindParam(":day",$day);
			$stmt->bindParam(":address",$address);
			$stmt->execute();
			$conn = null;
		}
		catch(PDOException $exception) {
			echo "Connection failed: " . $exception->getMessage();
		}
	}
	
	function edit_contacts() {
		try {
			$select = $_POST["select"];
			$name = htmlspecialchars($_POST["name"],ENT_QUOTES);
			$gender = htmlspecialchars($_POST["gender"],ENT_QUOTES);
			$phone = htmlspecialchars($_POST["phone"],ENT_QUOTES);
			$email = htmlspecialchars($_POST["email"],ENT_QUOTES);
			$year = htmlspecialchars($_POST["year"],ENT_QUOTES);
			$month = htmlspecialchars($_POST["month"],ENT_QUOTES);
			$day = htmlspecialchars($_POST["day"],ENT_QUOTES);
			$address = htmlspecialchars($_POST["address"],ENT_QUOTES);
			
			$conn = connDB();
			$stmt = $conn->prepare("update Contacts
				set name=:name, gender=:gender, phone=:phone, email=:email, year=:year, month=:month, day=:day, address=:address
				where email like :select");
			$stmt->bindParam(":name",$name);
			$stmt->bindParam(":gender",$gender);
			$stmt->bindParam(":phone",$phone);
			$stmt->bindParam(":email",$email);
			$stmt->bindParam(":year",$year);
			$stmt->bindParam(":month",$month);
			$stmt->bindParam(":day",$day);
			$stmt->bindParam(":address",$address);
			$stmt->bindParam(":select",$select);
			$stmt->execute();
			$conn = null;
		}
		catch(PDOException $exception) {
			echo "Connection failed: " . $exception->getMessage();
		}
	}
	
	function delete_contacts() {
		try {
			$conn = connDB();
			$stmt = $conn->prepare("delete from Contacts where email like :delete");
			$stmt->bindParam(":delete",$_POST["delete"]);
			$stmt->execute();
			$conn = null;
		}
		catch(PDOException $exception) {
			echo "Connection failed: " . $exception->getMessage();
		}
	}
	
?>
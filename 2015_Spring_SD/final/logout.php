<?php
	session_start();
	unset($_SESSION["login"]);
	header("refresh:0; url=http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php");
	exit;
?>
<?php
	require("main.php");

	$hello="hello";
	$str1="national Chung Cheng University";
	$str2="Computer and ";
	$str3="Time";
	//$str4
	$str5="add_8bit";
	$str6="YOU CAN DO YOUR BEST !!!";
	$str7="No pain,no gain.";

	$smarty->assign("hello",$hello);
	$smarty->assign("str1",$str1);
	$smarty->assign("str2",$str2);
	$smarty->assign("str3",$str3);
	$smarty->assign("str4",$str4);
	$smarty->assign("str5",$str5);
	$smarty->assign("str6",$str6);
	$smarty->assign("str7",$str7);

	$fav[0] = "fav0";
	$fav[1] = "fav1";
	$fav[2] = "fav2";
	$fav[3] = "fav3";

	$room[0] = "EA101";
	$room[1] = "EA105";
	$room[2] = "EA206";

	$smarty->assign("fav",$fav);
	$smarty->assign("room",$room);

	$smarty->display("index.tpl");
?>

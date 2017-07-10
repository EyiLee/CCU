<?php
	function reset_URI() {
		$URI = $_SERVER["SCRIPT_NAME"]."?";
		foreach($_GET as $key => $value) {
			$URI .= $key . "=" . $value . "&";
		}
		return $URI;
	}
?>
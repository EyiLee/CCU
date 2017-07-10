function loadPage(tar,href) {
	var xmlhttp = new XMLHttpRequest();
	xmlhttp.open("GET", href, false);
	xmlhttp.send();
	document.getElementById(tar).innerHTML = xmlhttp.responseText;
}
<!doctype html>
<html>
	<head></head>
	<body>
		{{$hello|replace:"hello":"Hello World!"}}<br>
		{{$str1|capitalize}}<br>
		{{$str2|cat:"Information and Engineering"}}<br>
		{{$str3|date_format:"%Yyear%mmonth%dday"}}<br>
		{{$str4|default:"NA"}}<br>
		{{$str5|indent:8:"*"}}<br>
		{{$str6|lower}}<br>
		{{$str7|replace:"No":"Have"|replace:"no":"have"}}<br>

		<table border="1">
		{{foreach from=$fav key=i item=vi }}
			{{if $i is not even}}
			<tr style="background-color:#DDD">
			{{else}}
			<tr>
			{{/if}}
				<td>{{$i}}</td>
				<td>{{$vi}}</td>
			</tr>
		{{/foreach}}
		</table>

		<select>
		{{foreach from=$room key=j item=vj }}
			<option>{{$vj}}</option>
		{{/foreach}}
		</select>
	</body>
</html>

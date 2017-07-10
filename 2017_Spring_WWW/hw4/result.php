<?php
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

    $lat = $_POST['lat'];
    $lng = $_POST['lng'];
    $dis = $_POST['dis'];

    $stmt = $conn->prepare("select `x`, `y`, `name`, `address`, (6371 * acos(cos(radians(?)) * cos(radians(y)) * cos(radians(x) - radians(?)) + sin(radians(?)) * sin(radians(y)))) as distance from Trainstation having distance < ? order by distance limit 10;");
	$stmt->bindParam(1, $lat);
	$stmt->bindParam(2, $lng);
	$stmt->bindParam(3, $lat);
	$stmt->bindParam(4, $dis);
    $stmt->execute();
	$result = $stmt->fetchAll(PDO::FETCH_BOTH);


    $obj2 = array();
    foreach ($result as $key => $station) {
        $feature = [
            'type' => 'Feature',
            'properties' => [
                'landmarkna' => $station["name"],
                'address' => $station["address"],
                'distance' => (float)$station["distance"]
            ],
            'geometry' => [
                'type' => 'Point',
                'coordinates' => [
                    (float)$station["x"],
                    (float)$station["y"]
                ]
            ]
        ];

        $obj2[$key] = $feature;
    }

    $obj = [
        'length' => count($result),
        'landmarkna' => [
            'type' => 'FeatureCollection',
            'features' => $obj2
        ]
    ];
    
    echo json_encode($obj, 384);
?>
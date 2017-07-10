var trainstationSource = new ol.layer.Vector({});
var markerSource = new ol.source.Vector({});
var markerLayer = null ; 

var AllMap = iniMap();

showClickPoint();

function iniMap() {
    var view = new ol.View({
        center: ol.proj.transform([121.0001, 23.5], 'EPSG:4326', 'EPSG:3857'),
        zoom: 7
    });

    var baseLayer = new ol.layer.Tile({
        source: new ol.source.OSM()
    });

    var layer = new ol.layer.Vector({
        source: new ol.source.Vector()
    });

    var map = new ol.Map({
        target: 'map-app',
        controls: ol.control.defaults().extend([
            new ol.control.ScaleLine(),
            new ol.control.ZoomSlider()
        ]),
        renderer: 'canvas',
        layers: [baseLayer],
        view: view
    });

    map.addLayer(layer);

    return map;
}


function showClickPoint() {
    AllMap.on('click', function(evt) {
        var lonlat = ol.proj.transform(evt.coordinate, 'EPSG:3857', 'EPSG:4326');
        var lng = lonlat[0];
        var lat = lonlat[1];

        var iconFeature = new ol.Feature({
            name: "icon",
            geometry: new ol.geom.Point(ol.proj.transform([lng, lat], 'EPSG:4326', 'EPSG:3857')),
        });

        var iconStyle = new ol.style.Style({
            image: new ol.style.Icon(({
                scale: 0.4,
                anchor: [0.5, 1],
                anchorXUnits: 'fraction',
                anchorYUnits: 'fraction',
                src: 'icon/allow.png'
            })),
        });

        markerSource.clear();
        markerSource.addFeature(iconFeature);

        AllMap.removeLayer(markerLayer);

        markerLayer = new ol.layer.Vector({
            source: markerSource,
            style: iconStyle
        });

        AllMap.addLayer(markerLayer);
        
        
        /*You should check the query ragne size before you query the train station*/
        var dis = document.querySelector('#dis').value;
        if (dis < 1 || dis > 10) {
            alert("Distance must between 1 to 10");
        } else {
    	    queryTrainsation(lat, lng, dis); // you should send lng,lat and query ragne size to this function
        }
    });
}

function showTrainstationPoint(trainstation) {
    AllMap.removeLayer(trainstationSource);
    
    trainstationSource = new ol.layer.Vector({
        source: new ol.source.Vector({
            features: (new ol.format.GeoJSON()).readFeatures(trainstation, { dataProjection: 'EPSG:4326', featureProjection: 'EPSG:3857' })
        })
    })

    AllMap.addLayer(trainstationSource);
}

function queryTrainsation(lat, lng, dis) {
    var req = new XMLHttpRequest();
    req.open('POST', 'result.php');
    req.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    req.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200 ) {
            var data = JSON.parse(this.responseText);
            showTrainstationPoint(data.landmarkna);
            showTable(data.landmarkna.features);
        }
    }
    var param = "lat=" + lat + "&lng=" + lng + "&dis=" + dis;
    req.send(param);
}

function showTable(data) {
    var table = document.querySelector('#search');
    var content = "";
    data.forEach(function(entry) {
        console.log(entry);
        content += "<tr>";
        content += "<td>" + entry.properties.landmarkna + "</td>";
        content += "<td>" + entry.properties.address + "</td>";
        content += "<td>" + entry.properties.distance + "</td>";
        content += "</tr>";
    })
    table.innerHTML = content;
}

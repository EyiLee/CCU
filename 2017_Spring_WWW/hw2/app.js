function renderPage() {
    var hash = location.hash.substring(1);
    if (hash === 'train') {
        var req = new XMLHttpRequest();
        req.open('GET', 'train.xml');
        req.overrideMimeType('text/xml');
        req.onload = function () {
            if (req.readyState === req.DONE) {
                if (req.status === 200) {
                    var doc = '<html><body>';
                    var xml = req.responseXML;
                    var train = xml.getElementsByTagName('train');
                    for (i = 0; i < train.length; i++) {
                        doc += '<table style="margin:0 auto;background-color:#e7e7e7">';
                        var type = train[i].getElementsByTagName('type')[0].childNodes[0].nodeValue;
                        var number = train[i].getElementsByTagName('number')[0].childNodes[0].nodeValue;
                        doc += '<tr style="background-color:#13aa7a;width:100%"><td colspan="9">' + type + ' - ' + number + '</td></tr>';
                        var start_station = train[i].getElementsByTagName('start_station')[0].childNodes[0].nodeValue;
                        var pass_1 = train[i].getElementsByTagName('pass_1')[0].childNodes[0].nodeValue;
                        var pass_2 = train[i].getElementsByTagName('pass_2')[0].childNodes[0].nodeValue;
                        var pass_3 = train[i].getElementsByTagName('pass_3')[0].childNodes[0].nodeValue;
                        var end_station = train[i].getElementsByTagName('end_station')[0].childNodes[0].nodeValue;
                        doc += '<tr>';
                        doc += '<td>' + start_station + '</td>';
                        doc += '<td>--></td>';
                        doc += '<td>' + pass_1 + '</td>';
                        doc += '<td>--></td>';
                        doc += '<td>' + pass_2 + '</td>';
                        doc += '<td>--></td>';
                        doc += '<td>' + pass_3 + '</td>';
                        doc += '<td>--></td>';
                        doc += '<td>' + end_station + '</td>';
                        doc += '</tr>';
                        var Time_start = train[i].getElementsByTagName('Time_start')[0].childNodes[0].nodeValue;
                        var Time_1 = train[i].getElementsByTagName('Time_1')[0].childNodes[0].nodeValue;
                        var Time_2 = train[i].getElementsByTagName('Time_2')[0].childNodes[0].nodeValue;
                        var Time_3 = train[i].getElementsByTagName('Time_3')[0].childNodes[0].nodeValue;
                        var Time_end = train[i].getElementsByTagName('Time_end')[0].childNodes[0].nodeValue;
                        doc += '<tr>';
                        doc += '<td>' + Time_start + '</td>';
                        doc += '<td></td>';
                        doc += '<td>' + Time_1 + '</td>';
                        doc += '<td></td>';
                        doc += '<td>' + Time_2 + '</td>';
                        doc += '<td></td>';
                        doc += '<td>' + Time_3 + '</td>';
                        doc += '<td></td>';
                        doc += '<td>' + Time_end + '</td>';
                        doc += '</tr>';
                        doc += '</table>';
                        doc += '</body></html>';
                    }
                    document.body.innerHTML = doc;
                }
            }
        };
        req.send();
    } else if (hash === 'MLB') {
        var req = new XMLHttpRequest();
        req.open('GET', 'MLB.xml');
        req.overrideMimeType('text/xml');
        req.onload = function () {
            if (req.readyState === req.DONE) {
                if (req.status === 200) {
                    var doc = '<html><head><style>table{border:1px solid;}tr,td{border:1px solid;text-align:center}</style></head><body>';
                    var xml = req.responseXML;
                    var baseball = xml.getElementsByTagName('baseball');
                    for (i = 0; i < baseball.length; i++) {
                        var color = baseball[i].getElementsByTagName('Color')[0].childNodes[0].nodeValue;
                        var bgcolor = baseball[i].getElementsByTagName('BColor')[0].childNodes[0].nodeValue;
                        doc += '<table width="720" style="margin:0px auto 100px;color:' + color + ';background-color:' + bgcolor + '">';
                        var team = baseball[i].getElementsByTagName('Team')[0].childNodes[0].nodeValue;
                        doc += '<tr><td height="160" colspan="5">' + team + '</td></tr>';
                        doc += '<tr><td>Image</td><td colspan="2">star</td><td>Coach</td><td>League</td></tr>';
                        var img = baseball[i].getElementsByTagName('Image')[0].childNodes[0].nodeValue;
                        doc += '<tr><td><img width="48" src="' + img + '"/></img></td>';
                        var name = baseball[i].getElementsByTagName('name')[0].childNodes[0].nodeValue;
                        var birth = baseball[i].getElementsByTagName('birth')[0].childNodes[0].nodeValue;
                        var coach = baseball[i].getElementsByTagName('Coach')[0].childNodes[0].nodeValue;
                        var league = baseball[i].getElementsByTagName('League')[0].childNodes[0].nodeValue;
                        doc += '<td>' + name + '</td>';
                        doc += '<td>' + birth + '</td>';
                        doc += '<td>' + coach + '</td>';
                        doc += '<td>' + league + '</td></tr>';
                        var video = baseball[i].getElementsByTagName('Video')[0].childNodes[0].nodeValue;
                        doc += '<tr><td colspan="5"><iframe width="720" height="480" src="' + video + '"></iframe></td></tr>'
                        doc += '</table>';
                    }
                    doc += '</body></html>';
                    document.body.innerHTML = doc;
                }
            }
        }
        req.send();

    }
}

function submitQuery () {
    var url = document.querySelector('[name="url"]').value;
    var req = new XMLHttpRequest();
    req.open('GET', url + '.xml');
    req.onload = function () {
        if (req.readyState === req.DONE) {
            if (req.status === 200) {
                window.open('index.html#' + url);
            } else {
                alert('Url is invalid.');
            }
        }
    };
    req.send();
}
<?php
    header("Content-Type:text/html; charset=utf-8");
    date_default_timezone_set("Asia/Taipei");
?>
<!DOCTYPE html>
<html lang="zh-Hant">
    <head>
        <title></title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="css/ol.css">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

        <script src="js/ol.js" defer="defer"></script>
        <script src="js/answer.js" defer="defer"></script>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js" defer="defer"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" defer="defer"></script>
    </head>

    <body>
        <header>
            <div class="container">
                <h1>Train Station Query System</h1>
                <form class="form-inline" onsubmit="return false;">
                    <div class="form-group">
                        <label class="sr-only" for="distance"></label>
                        <div class="input-group">
                            <div class="input-group-addon">Set distance between 1 to 10</div>
                            <input type="number" id="dis" class="form-control" value="1" min="1" max="10" required>
                            <div class="input-group-addon">KM</div>
                        </div>
                    </div>
                    <button type="submit" class="btn btn-primary">Submit</button>
                </form>
            </div>
        </header>
            
        <div class="container">
            <div class="row" style="padding-top:12px">
                <div class="col-sm-6">
                    <div id="map-app" style="height:calc(100vh - 115px)"></div>
                </div>
                <div class="col-sm-6">
                    <table class="table table-striped">
                        <tr>
                            <th>Name</th>
                            <th>Address</th>
                            <th>Distance</th>
                        </tr>
                        <tbody id="search">
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>

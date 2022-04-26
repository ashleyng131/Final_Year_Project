<?php include "db.php";?>

<html>
    <head>
        <title>Generate Line Chart in PHP</title>
        <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
        <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
        <style>
            body{
                background: #fff;
                
            }
            
            #my-chart{
                background: #fff;
                padding: 20px;
            }
            
        </style>
    </head>
    <body>

        <div id="DHT11" style="width: 1500px; height: 800px;"></div>
        <script type="text/javascript">
            google.charts.load('current', {
                'packages': ['corechart'],
                'mapsApiKey': ''   
            });
            google.charts.setOnLoadCallback(drawRegionsMap);

            function drawRegionsMap() {
                var data = google.visualization.arrayToDataTable([
                    ['Date', 'Temperature (°c)'],
                     <?php
                     $chartQuery = "SELECT * FROM DHT11";
                     $chartQueryRecords = mysqli_query($conn, $chartQuery);
                        while($row = mysqli_fetch_assoc($chartQueryRecords)){
                            echo "['".$row['date']."',".$row['temperature']."],";
                        }
                     ?>
                ]);

                var options = {
                title: 'The Line Chart of Temperature Tracking',
                curveType: 'function',
                legend: { position: 'bottom' }                
                   
                };

                var chart = new google.visualization.LineChart(document.getElementById('DHT11'));
                chart.draw(data, options);
            }
        </script>
    </head>
</body>
</html>
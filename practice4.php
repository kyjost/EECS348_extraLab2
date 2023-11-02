<!--
EECS 348 Lab 7
Webpage with fun font stuff going on. 
practice2.html
Ky Jost 
26 October 2023 
-->
<!DOCTYPE html> 
<html> 
    <head> 
        <title>PHP Tables </title>
    </head>

    <body>
        <?php 
            $num = $_POST["number"]; 
            
            echo "Multiplication table from 1 to $num <br><br>"; 

            for($i = 0; $i <= $num; $i++) {
                $myStr = substr("0000{$i}", -3); 
                echo "  " . $myStr . "  ";  
            }
            echo "<br>";

            for($i = 1; $i <= $num; $i++) {
                $myStr = substr("0000{$i}", -3); 
                echo "  " . $myStr . "  ";  
                for($j = 1; $j <= $num; $j++) {
                    $sum = $i * $j; 
                    $myStr = substr("0000{$sum}", -3); 
                    echo "  " . $myStr . "  "; 
                }
                echo "<br>"; 
            }
        ?> 
    </body>
</html>
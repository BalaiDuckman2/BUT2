<?php
require_once("depts-fix.php");      
require_once("regions.php");      





foreach ($_GET as $key => $value) {
    if ($key=="regions") {
        echo($value);
        ?>
        <ul>
        <?php
        foreach ($regions as $nom => $dept) {
            
            if ($nom==$value) {
                foreach ($dept as $numdep) {
                    foreach ($regions as $nomregion => $numregions) {
                        foreach ($numregions as $num) {
                            if ($num==$numdep) {
                                ?>
                                <li>
                                <?php echo($numdep)?>    
                                <li>
                                <?php
                            }
                        }
                    }
                }
                
            }
            
        }
        ?>
        </ul>
        <?php
    }
}

?>


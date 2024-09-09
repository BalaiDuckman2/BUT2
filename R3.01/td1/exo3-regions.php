<?php
require_once('/home/etuinfo/racorre/BUT2/R3.01/td1/regions.php');
?>

<ul> 
<?php
$compteur=4;
$compte=0;
foreach ($regions as $key => $value) {
    
    ?>
    
    <?php
    if($compte <= $compteur&& $compte>=$compteur-4){
        ?>
        <li>
        <?php echo($key); ?>
        </li>
        <?php
    }
    ?>
    
    
    <?php
    $compte=$compte+1;
}
?>
</ul>
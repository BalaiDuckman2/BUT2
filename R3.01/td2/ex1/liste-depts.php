<?php
require_once("depts-fix.php");      
require_once("regions.php");      
  
?>
<a href="form-reg.php">"crampté"</a>



<?php if($_GET['regions']!=null&&$_GET['dep']!=null){
foreach ($regions as $nom => $dept) { 
    if ($nom==$_GET['regions']) {
        echo($nom);
        
        
        foreach ($depts as $num => $nom) {
            
            foreach ($nom as  $value) {
                foreach($dept as $numero){

                
                if($numero==$num) {    
                        if (str_contains($value,$_GET['dep'])) {
                            echo($value); 
                        }
                    
                }
            }
        } 
    }
        
}
}

?>

<?php }else if ($_GET['regions']!=null) {
    


    foreach ($regions as $nom => $dept) { 
        if ($nom==$_GET['regions']) {
            foreach ($dept as $numdep) {
                foreach ($depts as $num => $nom) {
                    if($numdep==$num) {
                    ?>
                    <li>
                    <?php echo($nom[0])?>    
                    </li>
                    <?php
                    }
                }
            }
        }
    }
}else if ($_GET['dep']!=null) {


    
    foreach ($depts as $num => $nom) { 
        foreach ($nom as $key => $value) {
            if (str_contains($value,$_GET['dep'])) {
                    echo($value); 
                }
                   
                
            
        }


    }
}
?>


<ul>
<?php


<?php
if($_FILES['fichier']['name']==null){


?>
<form action="import.php" method="post" enctype="multipart/form-data">
    <label for="NomDep" >Fichier:</label>
    <input type="file" id="fichier"name="fichier">
 
    <input type="submit" value="Soumettre" />
</form>
<?php

    
}else{
    





    $fichier =file($_FILES['fichier']['tmp_name']);
    foreach ($fichier as $value) {
        $ligne =explode(';',$value,0);
        if(strlen($ligne[0])>40&&$ligne[0]=='H'||$ligne[0]=='F'){

        }else{
            
            file_put_contents('data.csv', $value, FILE_APPEND);
            
            
            
    }
    
    }
    
}
?>
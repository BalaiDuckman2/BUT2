<?php
require_once("regions.php");      
?>


<form action="liste-depts.php" method="get" enctype="multipart/form-data">
    <label for="NomDep" >Nom departement:</label>
    <input type="text" id="NomDep"name="dep">
    <br>
    <label for="regions">regions :</label>
        <select id="regions" name="regions">
            <option label="choisi" selected=true disabled=true></option>
            <?php
            foreach ($regions as $key => $value) {
                ?>
                
                <option value=<?php echo($key)?>><?php echo($key)?></option>
                <?php
            }
            ?>
            
        
        
        </select>
            <input type="submit" value="Soumettre" />
</form>
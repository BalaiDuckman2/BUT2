<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $fichier =file('data.csv');
    foreach ($fichier as $value) {
        $ligne =explode(';',$value,0);
        
        if($ligne[4]==$_POST['classe']){
            echo($value);
        }
            
            
            
    }
    print_r($ligne);
}else{
    
    
    


?>
<!DOCTYPE html>
<html>

<body>
    <h1>coubeh</h1>
    <form method="post" enctype="multipart/form-data">
        

        <label>Classe :</label><br>
        <select name="classe" required>
            <option value="6ème">6ème</option>
            <option value="5ème">5ème</option>
            <option value="4ème">4ème</option>
            <option value="3ème">3ème</option>
            <option value="Seconde">Seconde</option>
            <option value="Première">Première</option>
            <option value="Terminale">Terminale</option>
        </select><br><br>

        

        <button type="submit">ça part</button>
    </form>
</body>
</html>
<?php 
}
?>
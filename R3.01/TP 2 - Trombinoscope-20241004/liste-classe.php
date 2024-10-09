<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $fichier =file('data.csv');
    ?>
    <table>
        <caption><b>Classe de <?php echo($_POST['classe']); ?> <b></caption>
    <?php
    foreach ($fichier as $value) {
        $ligne =explode(';',$value);
        if($ligne[4]==$_POST['classe'][0]){
            ?>
            <table>
                
                <tr>
                    <td class="petit"><?php echo($ligne[5]);?></td>
                    <td  class="grand"><b><?php echo($ligne[0]);?></b></td>
                    <td class="grand"><?php echo($ligne[1]);?></td>
                    <td rowspan="2"> <img class="img" src="avatars/<?php echo(substr($ligne[3],0,13)); ?>.png" alt=""></td>

                </tr>
                <tr>
                    <td colspan="3"><?php echo($ligne[2]);?> </td>
                </tr>                
            </table>
            
            <?php
        }
            
            
            
    }
    ?>
    </table>
    <?php
    
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
            <option value="2">Seconde</option>
            <option value="1">Première</option>
            <option value="Terminal">Terminale</option>
        </select><br><br>

        

        <button type="submit">ça part</button>
    </form>
</body>
</html>

<?php
}
?>
<style>
table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
  padding:0 10px ;
  
}
.grand{
    width: 150px;
}
.petit{
    width: 5px;
}

.img{
    height:80px;
    padding:2px;
}
</style>
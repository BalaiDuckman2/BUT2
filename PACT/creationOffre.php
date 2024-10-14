<?php
include('connect_params.php');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    try {
    $dbh = new PDO("$driver:host=$server;dbname=$dbname", 
            $user, $pass);
    foreach($dbh->query('SELECT * from forum1._user', 
                        PDO::FETCH_ASSOC) 
                as $row) {
        
    }
    } catch (PDOException $e) {
        print "Erreur !: " . $e->getMessage() . "<br/>";
        die();
    }
}else{

?>



<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">

    <title>Création d'une offre</title>
</head>
<body>
    <img source="logo.png" alt="Logo">
    <h1>Créez votre Offre</h1>
    <form method="post" action="creationOffre.php" enctype="multipart/form-data">
        <label>Type de forfait</label><br>
        <select name="typeForfait" required>
            <option value="Standard">Standard</option>
            <option value="Premium">Premium</option>
        </select>
        <br>

        <label>Type d'offre</label><br>
        <select name="typeOffre" required>
            <option value="Standard">Activite</option>
            <option value="Premium">Visite</option>
            <option value="Standard">Spectacle</option>
            <option value="Premium">Parc d'attraction</option>
            <option value="Premium">Restauration</option>
        </select><br>

        <label>Type d'offre</label><br>
        <input type="text" name="ville" placeholder="Ville" required><br>
        <input type="number" name="codePostal" placeholder="code Postal" required><br>
        <input type="text" name="adressePostale" placeholder="Rue" required><br>
        
        <label>Numéro de téléphone</label><br>
        <input type="tel" name="numtel" placeholder="ex: 06 01 02 03 04" required><br>

        <label>Site Web</label><br>
        <input type="text" name="siteWeb" placeholder="ex: https://monsite.com" required><br>

        <label>Description de l'offre</label><br>
        <input type="text" name="descriptionOffre" required><br><br>

        <label>description Detaille</label><br>
        <input type="text" name="descriptionDetaille" required><br><br>

        <label>Tags</label><br>
        <input type="text" name="tags" required><br><br>

        <label>Photo</label><br>
        <input type="file" name="photo" required><br><br>
        <img src="" alt="">
        

        <label>Type de promotion de l'offre</label><br>
        <select name="typePromotion" required>
            <option value="Aucune">Activite</option>
            <option value="Relief">Visite</option>
            <option value="aLaUne">Spectacle</option>
        </select><br><br>
        
        <label>Tarif minimum</label><br>
        <input type="number" name="prix" required><br><br>

        <label>Durée du spectacle</label><br>
        <input type="time" name="tags" required><br><br>
        <label>Capacité d'accueil</label><br>
        <input type="number" name="tags" placeholder="Nombre de place" required><br><br>

        <button >Annuler</button>
        <button type="submit">Valider</button>
    </form>
    
    
</body>
</html>

<?php }?>
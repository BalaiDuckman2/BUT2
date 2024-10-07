<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $errors = [];
    $insee = $_POST['insee'];
    $nom = strtoupper($_POST['nom']);
    $prenom = ucwords(strtolower($_POST['prenom']));
    $email = $_POST['email'];
    $sexe = $_POST['sexe'];
    $classe = $_POST['classe'];
    
    
    
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Email incorrect";
    }
    
    if ($sexe != 'H' && $sexe != 'F') {
        $errors[] = "Sexe incorrect";
    }
    
    if (isset($_FILES['photo']) && $_FILES['photo']['size'] > 200 * 1024) { // 200 KB max
        $errors[] = "La photo dépasse la taille limite de 200 Ko.";
    }

    if (empty($errors)) {
        $photo = 'photos/' . $insee . '.jpg';
        move_uploaded_file($_FILES['photo']['tmp_name'], $photo);
        
        $line = "$insee,$nom,$prenom,$email,$sexe,$classe\n";
        file_put_contents('data.csv', $line, FILE_APPEND);
        echo "<p>Fiche ajoutée avec succès !</p>";
    } else {
        foreach ($errors as $error) {
            echo "<p>$error</p>";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Création d'une fiche</title>
</head>
<body>
    <h1>Création d'une fiche d'élève</h1>
    <form method="post" enctype="multipart/form-data">
        <label>Numéro INSEE :</label><br>
        <input type="text" name="insee" required><br><br>

        <label>Nom :</label><br>
        <input type="text" name="nom" required><br><br>

        <label>Prénom :</label><br>
        <input type="text" name="prenom" required><br><br>

        <label>Email :</label><br>
        <input type="email" name="email" required><br><br>

        <label>Sexe :</label><br>
        <input type="radio" name="sexe" value="H" required> Homme
        <input type="radio" name="sexe" value="F" required> Femme<br><br>

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

        <label>Photo :</label><br>
        <input type="file" name="photo" required><br><br>

        <button type="submit">Créer la fiche</button>
    </form>
</body>
</html>
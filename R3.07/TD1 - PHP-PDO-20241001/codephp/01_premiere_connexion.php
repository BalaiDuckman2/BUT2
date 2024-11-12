<?php
try {
    include('connect_params.php');
    $dbh = new PDO("$driver:host=$server;dbname=$dbname",
    $user, $pass);

    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $dbh->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    
    $stmt = $dbh->prepare("SELECT * FROM distribill_s3._personnel WHERE matr = :mat");

    $stmt->bindParam(':mat', $mat, PDO::PARAM_INT);

    $prenom=$_GET['prenom'];
    $mat=$_GET['mat'];
    
    $stmt = $dbh->prepare(
    "UPDATE distribill_s3._personnel SET nome = :prenom WHERE matr = :mat"
    );
    $stmt->bindParam(':prenom', $prenom, PDO::PARAM_STR);
    $stmt->bindParam(':mat', $mat, PDO::PARAM_INT);
    $stmt->execute();
    $dbh->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    $stmt = $dbh->prepare("SELECT * from distribill_s3._personnel");
    $stmt->execute();
    $result = $stmt->fetchAll();
    echo "<pre>";
    print_r($result);
    echo "</pre>";
    
    $dbh = null;
}catch (PDOException $e) {
    print "Erreur !: " . $e->getMessage() . "<br/>";
    die();
}
?>

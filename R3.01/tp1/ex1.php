<?php
    include('connect_params.php');
    $dbh = new PDO("$driver:host=$server;dbname=$dbname",
    $user, $pass);
    
    $dbh->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    $stmt = $dbh->prepare("SELECT * from distribill_s3._dept");
    $stmt->execute();
    $result = $stmt->fetchAll();
    echo "<pre>";
    print_r($result);
    echo "</pre>";
    $dbh = null;
?>
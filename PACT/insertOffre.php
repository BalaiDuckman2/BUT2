<?php
include('connect_params.php');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    try {
        $dbh = new PDO("$driver:host=$server;dbname=$dbname", 
                $user, $pass);
        foreach($dbh->query('SELECT * from forum1._user', 
                            PDO::FETCH_ASSOC) 
                    as $row) {
        echo("Offre ajoutée avec succès");
        
    }
    } catch (PDOException $e) {
        print "Erreur !: " . $e->getMessage() . "<br/>";
        die();
    }
}else{
}
?>
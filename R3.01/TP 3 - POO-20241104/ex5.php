<?php

class Coureur{
    public $nom;
    public $num;
    public $abandon=false;

    
    function __construct($nom,$num){
        $this->nom =$nom;
        $this->num =$num;
    }
}

class Equipe{
    public $num;
    public $listeCoureur=[];
    public $nom;

    function __construct($nom,$num){
        $this->nom =$nom;
        $this->num =$num;
        
    }

    function remplirListeCoureurs(){
        $tabCoureur=file("TDF_2023/TDF_2023/".trim(str_replace(" ", "_", $this->nom)));
        $compt=0;
        foreach ($tabCoureur as $coureur) {
            $compteur=0;
            if($compt!=0){
            $detaille=explode(" " ,$coureur);
            foreach ($detaille as  $value) {
                if ($compteur!=0) {
                    $nom  = $nom." ".$value;
                }
                $compteur+=1;
            }
            $this->listeCoureur[$detaille[0]]=new Coureur($nom,$detaille[0]);
            $nom=null;
            }
            $compt+=1;
        }
    }

    
}





$listeEquipe=[];
$tabEquipe=file("TDF_2023/TDF_2023/EQUIPES_TDF_2023");
$compteur=0;
foreach($tabEquipe as $equipe){
    $listeEquipe[$compteur]= new Equipe($equipe,$compteur);
    $listeEquipe[$compteur]->remplirListeCoureurs();
    $compteur+=1;
}
foreach($listeEquipe as $equipe){
    ?>
    <table>
        <thead>
            <tr>
                <th colspan="2"><?php echo($equipe->nom)?></th>
            </tr>
        </thead>
        
            <?php foreach($equipe->listeCoureur as $coureur){?>
                <tr>
                <td><?php echo($coureur->num) ?></td>
                <td><?php echo($coureur->nom) ?></td>
                </tr>
            <?php }?>
            
            
        
    <table>
    <?php
}
?>
let mot = new String();
mot = prompt("Entrez un mot");
let premiereLettre;
premiereLettre= mot.charAt(0);
let compteur=0;
let debut="";
let fin="";
alert(mot.length());
while(compteur<mot.length()){
    switch(mot[compteur]){
        case 'b':
            debut=mot.slice(0,compteur);
            fin=mot.slice(compteur+1);
            debut.concat("em");
            alert(debut)
            break

        case 'm':

            break

        case 'c':

            break

        case 'd':

            break
        
        case 'p':

            break
    }
    
}
^[1-9][0-9]{1,3}[A-HJ-NP-TV-Z]{2,3}(0[0-9]|[[1-8][0-9]|9[0-5]|2[AB])$
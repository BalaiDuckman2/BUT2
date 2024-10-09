let play = 'o';
while (play == 'o') {
    let nbcoup = 0;
    let trouve = Math.random();
    trouve *= 100;
    trouve = Math.round(trouve);
    let cherche = -1;
    while (cherche != trouve && cherche != 1) {
        cherche = prompt("chiffre");
        if (cherche > trouve) {
            alert("trop grand")
        } else if (cherche < trouve) {
            alert("trop petit")
        }
        nbcoup += 1;
    }

    alert("gg")
    play = prompt("rejouer(o/n)");
}

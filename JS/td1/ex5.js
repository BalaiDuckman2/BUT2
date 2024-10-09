function calculerPerimEtSurf(longueur, largeur = longueur) {

    let surface = longueur * largeur;
    let perim = longueur * 2 + largeur * 2;
    return { perim, surface };
}
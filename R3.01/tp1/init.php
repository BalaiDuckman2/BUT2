
<?php

// Read the content of the 'articles' file
$lines = file('articles', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

// Initialize the articles array
$articles = [];

// Process each line
foreach ($lines as $line) {
    // Split the line into components
    $parts = explode(';', $line);
    
    // Ensure we have all required parts
    if (count($parts) === 4) {
        $code = intval($parts[0]);
        $libelle = trim($parts[1]);
        $prixHT = floatval(str_replace(',', '.', $parts[2]));
        $tauxTVA = floatval(str_replace(',', '.', $parts[3]));
        
        // Add the article to the array with additional fields
        $articles[$code] = [
            'libelle' => $libelle,
            'prixHT' => $prixHT,
            'tauxTVA' => $tauxTVA,
            'stock' => 0,
            'vendu' => 0
        ];
    }
}

// Serialize and save the articles array to 'data' file
file_put_contents('data', serialize($articles));


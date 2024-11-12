-- Table Compétiteur
CREATE TABLE Competiteur (
    CompetiteurID INT PRIMARY KEY,
    Nom VARCHAR(50),
    Prenom VARCHAR(50),
    Age INT
);

-- Table Compétition
CREATE TABLE Competition (
    CompetitionID INT PRIMARY KEY,
    Nom VARCHAR(50),
    Date DATE
);

-- Table Épreuve
CREATE TABLE Epreuve (
    EpreuveID INT PRIMARY KEY,
    CompetitionID INT,
    Nom VARCHAR(50),
    Type VARCHAR(50),
    FOREIGN KEY (CompetitionID) REFERENCES Competition(CompetitionID) 
        ON DELETE CASCADE
);

-- Table Participation (associant Compétiteur, Épreuve et Compétition)
CREATE TABLE Participation (
    CompetiteurID INT,
    EpreuveID INT,
    CompetitionID INT,
    PRIMARY KEY (CompetiteurID, EpreuveID, CompetitionID),
    FOREIGN KEY (CompetiteurID) REFERENCES Competiteur(CompetiteurID) 
        ON DELETE CASCADE,
    FOREIGN KEY (EpreuveID) REFERENCES Epreuve(EpreuveID) 
        ON DELETE CASCADE,
    FOREIGN KEY (CompetitionID) REFERENCES Competition(CompetitionID)
        ON DELETE CASCADE,
    CHECK (CompetitionID = (SELECT CompetitionID FROM Epreuve WHERE EpreuveID = Participation.EpreuveID))
);

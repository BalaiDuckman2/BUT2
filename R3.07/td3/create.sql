CREATE TABLE Competition (
    competition_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    date DATE NOT NULL,
    location VARCHAR(100)
);

CREATE TABLE Competitor (
    competitor_id INT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    birth_date DATE,
    UNIQUE(first_name, last_name, birth_date)
);

CREATE TABLE Event (
    event_id INT PRIMARY KEY,
    competition_id INT NOT NULL,
    event_name VARCHAR(100) NOT NULL,
    event_type VARCHAR(50),
    FOREIGN KEY (competition_id) REFERENCES Competition(competition_id) 
    ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Participation (
    participation_id INT PRIMARY KEY,
    competitor_id INT NOT NULL,
    event_id INT NOT NULL,
    result_time TIME,
    FOREIGN KEY (competitor_id) REFERENCES Competitor(competitor_id) 
    ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (event_id) REFERENCES Event(event_id) 
    ON DELETE CASCADE ON UPDATE CASCADE,
    CONSTRAINT chk_competitor_in_competition 
    CHECK (event_id IN (SELECT event_id FROM Event WHERE Event.competition_id = (SELECT competition_id FROM Event WHERE Event.event_id = event_id)))
);

CREATE TABLE CompetitionRegistration (
    registration_id INT PRIMARY KEY,
    competitor_id INT NOT NULL,
    competition_id INT NOT NULL,
    FOREIGN KEY (competitor_id) REFERENCES Competitor(competitor_id) 
    ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (competition_id) REFERENCES Competition(competition_id) 
    ON DELETE CASCADE ON UPDATE CASCADE,
    UNIQUE (competitor_id, competition_id)
);

ALTER TABLE Participation
ADD CONSTRAINT fk_registered_competitor
FOREIGN KEY (competitor_id, event_id)
REFERENCES CompetitionRegistration(competitor_id, competition_id);

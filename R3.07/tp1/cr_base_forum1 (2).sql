DROP SCHEMA IF EXISTS tp CASCADE;

CREATE SCHEMA tp;
SET SCHEMA 'tp';

--CREATION DES TABLES

CREATE TABLE _judoka(
	idJudoka		SERIAL			CONSTRAINT _judoka_pk PRIMARY KEY,
	nom 		VARCHAR(20)	NOT NULL,
	prenom 		VARCHAR(20)	NOT NULL,
	age INTEGER not NULL,
	poids DECIMAL not null,
	victoires INTEGER,
	defaites INTEGER
	CONSTRAINT _poid
		CHECK (poids >= 80)

);

CREATE TABLE _senior(
  idjudoka SERIAL CONSTRAINT _senior_pk PRIMARY KEY,
  CONSTRAINT _senior_fk_judoka
		FOREIGN KEY (idjudoka) REFERENCES _judoka(idJudoka)
	);
	
CREATE TABLE _junior(
  idjudoka SERIAL CONSTRAINT _junior_pk PRIMARY KEY,
  CONSTRAINT _junior_fk_judoka
		FOREIGN KEY (idjudoka) REFERENCES _judoka(idJudoka)
	);
  

CREATE TABLE _combat(
  idCombat SERIAL			CONSTRAINT _combat_pk PRIMARY KEY,
  duree DECIMAL,
  date_combat DATE NOT NULL,
  idjudoka1 INTEGER NOT NULL,
  idjudoka2 INTEGER NOT NULL,
  idvainqueur INTEGER,
  CONSTRAINT _combat_fk_judoka1
		FOREIGN KEY (idjudoka1) REFERENCES _judoka(idJudoka),
	CONSTRAINT _combat_fk_judoka2
		FOREIGN KEY (idjudoka2) REFERENCES _judoka(idJudoka),
	CONSTRAINT _combat_fk_vainqueur
		FOREIGN KEY (idvainqueur) REFERENCES _judoka(idJudoka)
  );
  
  

CREATE TABLE _entrainement(
  idjudoka INTEGER NOT NULL,
  idsenior INTEGER NOT NULL,
  CONSTRAINT _entrainement_fk_judoka
		FOREIGN KEY (idjudoka) REFERENCES _judoka(idJudoka),
	CONSTRAINT _entrainement_fk_senior
		FOREIGN KEY (idsenior) REFERENCES _senior(idJudoka)
);

--CREATION DE LA VUE

CREATE OR REPLACE VIEW StatistiquesJudoka as
SELECT idJudoka,nom,prenom,victoires,defaites
FROM _judoka;

--CREATION DE LA FONCTION

CREATE OR REPLACE FUNCTION combatmax() RETURNS TRIGGER AS $$
BEGIN
  IF((SELECT COUNT(idCombat) FROM _combat where date_combat = new.date_combat)>=5) THEN
    RAISE EXCEPTION 'Impossible déjà plus de 5 combat le meme jours';
  END IF;
  RETURN new;
END;
$$ LANGUAGE plpgsql;

--CREATION DU TRIGGER
CREATE TRIGGER combatmax
BEFORE INSERT
ON _combat
FOR EACH ROW
EXECUTE PROCEDURE combatmax();

--TEST

START TRANSACTION;
insert into _judoka VALUES(1,'corre','raphael',18,80,1,10);
insert into _judoka VALUES(2,'jean','dupuit',40,85,3,4);
INSERT into _senior VALUES(2);
INSERT into _junior VALUES(1);
insert into _combat VALUES(1,14,'14/10/2024',1,2,1);
insert into _combat VALUES(2,20,'14/10/2024',1,2,1);
insert into _entrainement VALUES(1,2);
select * from _judoka;
select * from _junior;
select * from _senior;
select * from _entrainement;
select * from _combat;
select * from StatistiquesJudoka;
insert into _combat VALUES(3,30,'14/10/2024',1,2,1);
insert into _combat VALUES(4,40,'14/10/2024',1,2,1);
insert into _combat VALUES(5,50,'14/10/2024',1,2,1);
insert into _combat VALUES(6,60,'14/10/2024',1,2,1);
insert into _combat VALUES(7,70,'14/10/2024',1,2,1);
ROLLBACK;
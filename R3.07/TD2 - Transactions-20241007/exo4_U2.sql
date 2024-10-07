START TRANSACTION ;

UPDATE enfant SET points = points + 7 WHERE nopers = 2 ;

UPDATE enfant SET points = points + 11 WHERE nopers = 1 ;

COMMIT ;

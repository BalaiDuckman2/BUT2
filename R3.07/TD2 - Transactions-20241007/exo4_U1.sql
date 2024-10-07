START TRANSACTION ;

UPDATE enfant SET points = points + 5 WHERE nopers = 1 ;

UPDATE enfant SET points = points + 9 WHERE nopers = 2 ;

COMMIT ;

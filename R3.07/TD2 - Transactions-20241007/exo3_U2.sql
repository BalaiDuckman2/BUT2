START TRANSACTION ;

SELECT points FROM enfant WHERE nopers = 1 FOR UPDATE ;

UPDATE enfant SET points = points + 5 WHERE nopers = 1 ;

COMMIT ;

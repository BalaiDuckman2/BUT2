

SET SCHEMA 'forum2';

-- VUE USER

create or replace view user_view as
select * 
from _user;

-- VUE COMMENT

create or replace view comment_view as
select iddoc, content, create_date,author
from _comment natural join _document;

-- VUE POST

create or replace view post_view as
select iddoc, content, create_date,author
from _post natural join _document;

-- q1

CREATE OR REPLACE FUNCTION erreurView() RETURNS TRIGGER AS $$
BEGIN
  IF(old.nickname != new.nickname) THEN
    RAISE EXCEPTION 'RAPH T''ES UNE MERDE';
  END IF;
  UPDATE _user SET pass = new.pass WHERE old.nickname = nickname;
  UPDATE _user SET email = new.email WHERE old.nickname = nickname;
  RETURN new;
END;
$$ LANGUAGE plpgsql;


DROP TRIGGER IF EXISTS U_user ON user_view;

CREATE TRIGGER U_user
INSTEAD OF UPDATE
ON user_view
FOR EACH ROW
EXECUTE PROCEDURE erreurView();

UPDATE user_view
SET pass = 'test'
WHERE nickname = 'Thomas';

/*UPDATE user_view
SET nickname = 'test'
WHERE nickname = 'Thomas';*/

-- q2

CREATE OR REPLACE FUNCTION erreurView() RETURNS TRIGGER AS $$
BEGIN
  IF(old.nickname != new.nickname) THEN
    RAISE EXCEPTION 'RAPH T''ES COOL';
  END IF;
  UPDATE _user SET email = new.email WHERE old.nickname = nickname;
  RETURN new;
END;
$$ LANGUAGE plpgsql;


DROP TRIGGER IF EXISTS U_user ON user_view;

CREATE TRIGGER U_user
INSTEAD OF UPDATE
ON user_view
FOR EACH ROW
EXECUTE PROCEDURE erreurView();

UPDATE user_view
SET pass = 'test'
WHERE nickname = 'Thomas';

-- q3

CREATE OR REPLACE FUNCTION erreurCreerView() RETURNS TRIGGER AS $$
BEGIN
  IF(old.nickname != new.nickname) THEN
    RAISE EXCEPTION 'RAPH T''ES COOL';
  END IF;
  UPDATE _user SET pass = new.pass WHERE old.nickname = nickname;
  UPDATE _user SET email = new.email WHERE old.nickname = nickname;
  RETURN new;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS C_post ON post_view;

CREATE OR replace TRIGGER  C_post
INSTEAD OF INSERT
ON user_view
FOR EACH ROW
EXECUTE PROCEDURE erreurView();

UPDATE user_view
SET pass = 'test'
WHERE nickname = 'Thomas';



CREATE OR REPLACE FUNCTION remplacement() RETURNS TRIGGER AS $$
BEGIN
  UPDATE _document set author = 'Anonymous' where author = old.nickname ;
  DELETE FROM _user WHERE nickname = old.nickname;
  RETURN new;
END;
$$ LANGUAGE plpgsql;


CREATE OR replace TRIGGER  userSup
INSTEAD OF DELETE
ON user_view
FOR EACH ROW
EXECUTE PROCEDURE remplacement();

DELETE FROM user_view WHERE nickname = 'Alex';


CREATE OR REPLACE FUNCTION creation() RETURNS TRIGGER AS $$
declare 
  iddoctemp _document.iddoc%type;
BEGIN
  INSERT into _document(content,author) values(NEW.content,NEW.author)
    Returning iddoc into iddoctemp;
    INSERT into  _post(iddoc) values(iddoctemp);
  RETURN NULL;
END;
$$ LANGUAGE plpgsql;



CREATE OR replace TRIGGER  creePost
INSTEAD OF INSERT
ON post_view
FOR EACH ROW
EXECUTE PROCEDURE creation();

insert into post_view(content,author)
  values('Lorem ipsum dolor sit amet, consectetur adipiscing elit. ','Jean');
  

CREATE OR REPLACE FUNCTION modif() RETURNS TRIGGER AS $$

BEGIN
  IF(old.author != new.author) and (old.iddoc != new.iddoc) THEN
    RAISE EXCEPTION 'Imposible';
  END IF;
  update _document set content=new.content where old.content=content;

  RETURN NULL;
END;
$$ LANGUAGE plpgsql;



CREATE OR replace TRIGGER  att
INSTEAD OF UPDATE
ON post_view
FOR EACH ROW
EXECUTE PROCEDURE modif();

update post_view set content = 'seiryoku zenyo !' where iddoc = 2;


CREATE OR REPLACE FUNCTION sup() RETURNS TRIGGER AS $$

BEGIN
  DELETE FROM _post WHERE iddoc =old.iddoc ;
  DELETE FROM _comment WHERE iddoc =old.iddoc ;
  DELETE FROM _comment WHERE ref =old.iddoc ;
  DELETE FROM _document WHERE iddoc =old.iddoc ;
  
  RETURN NULL;
END;
$$ LANGUAGE plpgsql;



CREATE OR replace TRIGGER  att
INSTEAD OF DELETE
ON post_view
FOR EACH ROW
EXECUTE PROCEDURE sup();

delete from post_view where iddoc = 2;

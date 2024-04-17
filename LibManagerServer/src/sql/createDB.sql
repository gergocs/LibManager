create table if not exists record
(
    id   uuid  not null
        constraint id_pk
            primary key,
    data jsonb not null
);



CREATE OR REPLACE FUNCTION hash_password()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS
$$
BEGIN
    NEW.password = sha256(NEW.password::bytea);
    RETURN NEW;
END;
$$;

create table if not exists users
(
    id          integer generated always as identity
        constraint users_pk
            primary key,
    username    text              not null
        constraint users_pk_2
            unique,
    password    text              not null,
    permissions integer default 0 not null
);

create or replace  trigger create_user_hash_trigger
    before insert
    on users
    for each row
execute procedure hash_password();

create or replace trigger update_user_hash_trigger
    before update
    on users
    for each row
    WHEN ( OLD.password IS DISTINCT FROM NEW.password)
execute procedure hash_password();

SELECT *
FROM users
WHERE username = 'test'
  AND password = sha256('test2'::bytea)::text;
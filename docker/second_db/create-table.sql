create table domains (id INT NOT NULL AUTO_INCREMENT, name TEXT, allow INT, PRIMARY KEY(id));

insert into domains (name, allow) values('nix.ru', '1');
insert into domains (name, allow) values('test.ru', '1');


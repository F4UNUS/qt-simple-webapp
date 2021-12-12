DROP DATABASE IF EXISTS test_webapp_db;
CREATE DATABASE test_webapp_db;
USE test_webapp_db;

CREATE TABLE users(
	id int NOT NULL PRIMARY KEY AUTO_INCREMENT,
  	name char(60)
) 

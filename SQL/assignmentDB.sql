create database if not exists mysiblings;

use mysiblings;

create table users(
	id int primary key identity(1,1) not null,
	name varchar(255),
	pass varchar(255) not null,
	email varchar(255) unique not null
)

create table siblings(
	
	id int identity(1,1) primary key not null,
	name varchar(255),
	phone varchar(11) null,
	age int check(age > 0),
	gender varchar(155) not null,
	residence varchar(255),
	bloodgrp varchar(255)

)


create table institution(
	id int identity(1,1) primary key not null,
	name varchar(255),
	place varchar(255),
	instype varchar(255),
	class varchar(255),
	sibling int foreign key references siblings(id)
)

create table incidents(
	id int identity(1,1) primary key not null,
	incident varchar(255) not null,
	sibling int foreign key references siblings(id)
)

create table occupations(
	id int identity(1,1) primary key not null,
	employer varchar(255),
	position varchar(255),
	income int
)

create table birthday(
	id int identity(1,1) primary key not null,
	dob date not null,
	tob time not null,
	sibling int foreign key references siblings(id)


)

create table siblingdeath(
	id int identity(1,1) primary key not null,
	deathtime datetime not null,
	sibling int foreign key references siblings(id)

)

create table familygrave(
	id int identity(1,1) primary key not null,
	size varchar(255),
	death int foreign key references siblingdeath(id)

)


create table marriges(
	id int identity(1,1) primary key not null,
	dateOfMarrige date,
	destination varchar(255),
	expense int

)


create table spouse(
	id int identity(1,1) primary key not null,
	name varchar(255),
	age int,
	marrige int foreign key references marriges(id)
)


create table adult(

	id int identity(1,1) primary key references siblings(id) not null,
	spouse int foreign key references spouse(id),

	occupation int foreign key references occupations(id)
 

)


create table elderly(
	id int identity(1,1) primary key references siblings(id) not null,
	spouse int foreign key references spouse(id),
	occupation int foreign key references occupations(id)

)

create table child(
	id int identity(1,1) primary key references siblings(id) not null
	

)

create table teenager(
	id int identity(1,1) primary key references siblings(id) not null,
	
	occupation int foreign key references occupations(id)

)

create table babysitter(

	id int identity(1,1) primary key not null,
	name varchar(255),
	age int not null,
	employer varchar(255)

)

create table infant(
	id int identity(1,1) primary key references siblings(id) not null,
	bbs int foreign key references babysitter(id)
	

)



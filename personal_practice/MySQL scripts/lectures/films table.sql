show databases;

create database cinema_booking_system;

use cinema_booking_system;

create table flims
{
    id int primary key auto_increment,
    name varchar(45) not null unique,
    length_min int not null
};
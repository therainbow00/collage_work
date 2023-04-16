use cinema_booking_system;

create table customers
(
    id int primary key auto_increment,
    first_name varchar(45),
    last_name varchar(45) not null,
    email varchar(45) not null unique
);

show tables;

select * from customers;

describe customers;
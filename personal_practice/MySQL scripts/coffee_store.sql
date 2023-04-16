show databases;

create database coffee_store;
use coffee_store;
create table products 
(
	id int auto_increment primary key,
    name varchar(30),
    price decimal(3, 2)
);

create table customers
(
	id int auto_increment primary key,
	first_name varchar(100),
    last_name varchar(100),
    gender enum('M', 'F'),
    phone_number varchar(11)
);

create table orders
(
	id int auto_increment primary key,
    product_id int,
    customer_id int,
    order_time datetime,
    foreign key (product_id) references products(id),
    foreign key (customer_id) references customers(id)
);

show tables;
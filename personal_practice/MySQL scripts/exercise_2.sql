use coffee_store;
select * from customers;
select * from products;

select first_name, phone_number from customers
where gender = 'F' and last_name = 'Bluth';

select name from products
where price > 3 or coffee_origin = 'Sri Lanka';

select * from customers
where gender = 'M' and phone_number is null;
use cinema_booking_system;
select concat(first_name, last_name) as full_name from customers;
select concat(first_name, " ", last_name) as full_name from customers;
select concat(first_name, " ", last_name, " ", email) as full_name from customers;
select concat("This is ", first_name, " ", last_name, "'s email: ", email) as customers_email from customers;
use cinema_booking_system;

select concat(name, ": ", length_min) as name_and_length from films;

select substring(email, 5) as extracted_email from customers;

select lower(first_name) as lower_first, upper(last_name) as upper_last from customers where last_name = 'Smith';

select substring(name, -3) as last_3_letters from films;

select concat(substring(first_name, 1, 3), " ", substring(last_name, 1, 3)) as short_name from customers;
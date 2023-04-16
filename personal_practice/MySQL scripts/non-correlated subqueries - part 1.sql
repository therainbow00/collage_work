use cinema_booking_system;

select id, start_time from screenings where film_id in (select id from films where length_min > 120);

select id from films where length_min > 120;

select * from customers;
select * from bookings;

select first_name, last_name, email from customers where id in (select customer_id from bookings where screening_id = 1);

select customer_id from bookings where screening_id = 1;
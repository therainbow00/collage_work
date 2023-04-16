use cinema_booking_system;

select count(*) from bookings
where customer_id = 10;


select count(*) from screenings
s join films f on s.film_id = f.id
where f.name = 'Blade Runner 2049';


select count(distinct(customer_id)) from bookings;
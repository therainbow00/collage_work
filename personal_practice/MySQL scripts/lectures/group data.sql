use cinema_booking_system;

select * from bookings;

select customer_id, screening_id, count(id) from bookings
group by customer_id, screening_id;

select f.name, s.start_time, c.first_name, c.last_name, count(b.id) from films f 
join screenings s on f.id = s.film_id
join bookings b on s.id = b.screening_id
join customers c on b.customer_id = c.id
group by f.name, c.last_name, c.first_name, s.start_time
order by s.start_time;
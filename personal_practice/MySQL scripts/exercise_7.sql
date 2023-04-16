use cinema_booking_system;

select b.customer_id, count(rs.id) from bookings b
join reserved_seat rs on b.id = rs.booking_id
group by b.customer_id;


select f.name, f.length_min, count(s.id) from films f
join screenings s on f.id = s.film_id
group by f.name, f.length_min
having f.length_min > 120;
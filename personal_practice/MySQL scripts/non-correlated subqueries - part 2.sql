use cinema_booking_system;

select * from reserved_seat;

select avg(no_seats), max(no_seats) from (select booking_id, count(seat_id) as no_seats from reserved_seat group by booking_id) b;
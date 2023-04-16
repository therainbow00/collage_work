use cinema_booking_system;

select screening_id, customer_id from bookings order by screening_id;

select screening_id, customer_id, (select count(seat_id) from reserved_seat where booking_id = b.id) from bookings b order by screening_id;

select count(seat_id) from reserved_seat where booking_id = b.id;
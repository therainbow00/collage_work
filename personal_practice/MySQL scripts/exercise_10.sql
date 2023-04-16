use cinema_bookings_system;

select film_id, start_time from screenings where date(start_time) = '2017-10-20';

select * from screenings where date(start_time) between '2017-10-6' and '2017-10-13';

select * from screenings where year(start_time) = '2017' and month(start_time) = '10';
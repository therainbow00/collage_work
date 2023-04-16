use cinema_booking_system;

select year('2018-06-05 07:42:45');
select year(start_time) from screenings;

select * from screenings where year(start_time) = '2017';
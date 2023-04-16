use cinema_booking_system;

select month('2018-06-05 07:45:32');

select start_time from screenings;
select month(start_time) from screenings;
select * from screenings where month(start_time) = '10';
use cinema_booking_system;

select substring("Example", 3) as sub;

select name from films;

select substring(name, 1, 3) as short_name from films;
select substring(name, 5, 4) as short_name from films;
select substring(name, -2, 2) as short_name from films;
select substring(name, -6, 5) as short_name from films;
use cinema_booking_system;

select name, length_min from films where length_min > (select avg(length_min) from films);

select max(id), min(id) from (select film_id, count(id) as id from screenings group by film_id) a;

select name, (select count(id) from screenings where film_id = f.id) from films f;
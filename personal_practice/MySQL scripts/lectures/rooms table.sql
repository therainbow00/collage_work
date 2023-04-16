use cinema_booking_system;

create table rooms
(
    id int primary key auto_increment,
    name varchar(45) not null,
    no_seats int not null
);

show tables;

select * from rooms;

describe rooms;
use cinema_booking_system;

create table seats
(
    id int primary key auto_increment,
    seat_row char(1) not null,
    number int not null,
    room_id int not null,
    foreign key (room_id) references rooms(id)
);

show tables;

describe seats;

use cinema_booking_system;

create table reserved_seat
(
    id int primary key auto_increment,
    booking_id int not null,
    seat_id int not null,
    foreign key (booking_id) references bookings(id), 
    foreign key (seat_id) references seats(id) 
);

show tables;

describe reserved_seat;
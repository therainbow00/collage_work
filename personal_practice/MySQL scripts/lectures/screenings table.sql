use cinema_booking_system;

create table screenings
(
    id int primary key auto_increment,
    film_id int not null,
    rooms_id int not null,
    start_time datetime not null,
    foreign key (film_id) references films(id),
    foreign key (rooms_id) references rooms(id)
);

show tables;

describe screenings;
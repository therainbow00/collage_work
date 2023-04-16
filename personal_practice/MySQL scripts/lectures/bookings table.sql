use cinema_booking_system;

create table bookings
(
    id int primary key auto_increment,
    screening_id int not null,
    customer_id int not null,
    foreign key (screening_id) references screenings(id),
    foreign key (customer_id) references customers(id)
);

show tables;

describe bookings;
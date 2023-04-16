use test;
describe pets;
describe people;
describe addresses;

alter table pets
add primary key (id);

alter table people
add primary key (id);

alter table pets
add constraint fk_owner_id
foreign key (owner_id) references people(id);

alter table people
add column email varchar(30);

alter table people
add constraint c_email unique (email);

alter table pets change `name` `first_name` varchar(20);

alter table addresses modify postcode char(7);
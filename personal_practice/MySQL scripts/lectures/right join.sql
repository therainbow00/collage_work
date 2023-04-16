use coffee_store;

select * from orders;
select * from products;

update orders
set customer_id = 1
where id = 1;

select o.id, c.phone_number, c.last_name, o.order_time from orders o
right join customers c on o.customer_id = c.id
order by o.order_time limit 10;
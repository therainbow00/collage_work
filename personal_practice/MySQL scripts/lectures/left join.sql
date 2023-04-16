use coffee_store;

select * from orders;
select * from products;

update orders
set customer_id = NULL
where id = 1;

select o.id, c.phone_number, c.last_name, o.order_time from customers c
left join orders o on c.id = o.customer_id
order by o.order_time;
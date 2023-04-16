use coffee_store;

select o.id, c.phone_number from orders o join customers c on o.customer_id = c.id where o.product_id = 4;

select p.name, o.order_time from products p join orders o on p.id = o.product_id where p.name = 'Filter' and o.order_time between '2017-01-15' and '2017-02-14';

select p.name, p.price, o.order_time from products p join orders o on p.id = o.product_id join customers c on o.customer_id = c.id where c.gender = 'F' and o.order_time between '2017-01-01' and '2017-01-31';
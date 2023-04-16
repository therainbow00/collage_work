use coffee_store;
select name, price from products where coffee_origin in('Colombia', 'Indonesia') order by name;

select * from orders where order_time between '2017-02-01' and '2017-02-28' and customer_id in(2, 4, 6, 8);

select first_name, phone_number from customers where last_name like '%ar%';
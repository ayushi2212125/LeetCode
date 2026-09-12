SELECT sell_date,
       count(distinct product) as num_sold,
       GROUP_CONCAT(DISTINCT product order by product ) AS products
FROM Activities
group by sell_date
order by sell_date;       

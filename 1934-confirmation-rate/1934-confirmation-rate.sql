SELECT s.user_id,
       ROUND(coalesce(sum(c.action ='confirmed')/count(c.action),0),2) AS confirmation_rate
FROM Signups as s
left Join Confirmations as c
ON s.user_id = c.user_id
group by s.user_id;


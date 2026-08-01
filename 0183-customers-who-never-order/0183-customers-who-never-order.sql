SELECT c.name AS Customers
FROM Customers as c
left join Orders as o
ON c.id = o.customerId
WHERE o.customerId IS NULL;

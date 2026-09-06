SELECT m.name
FROM Employee as e
Join Employee as m
ON e.managerId = m.Id
GROUP BY m.name,m.id
HAVING count(e.id) >= 5


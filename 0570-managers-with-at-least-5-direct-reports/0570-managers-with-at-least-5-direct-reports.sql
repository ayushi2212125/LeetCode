SELECT m.name
FROM Employee as e
Join Employee as m
ON e.managerId = m.id
GROUP BY m.name,m.id
having count(e.id) >= 5;
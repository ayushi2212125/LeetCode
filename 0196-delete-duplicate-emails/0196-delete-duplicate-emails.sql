
DELETE p
FROM Person as p
JOIN Person as q
ON p.email = q.email
where p.id > q.id;
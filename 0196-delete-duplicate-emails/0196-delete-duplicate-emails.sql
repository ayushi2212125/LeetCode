DELETE p
FROM Person as p
JOIN Person as q
ON p.email = q.email
WHERE p.id > q.id;
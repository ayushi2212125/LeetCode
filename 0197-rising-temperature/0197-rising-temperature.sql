SELECT w2.id
FROM Weather as w1
JOIN Weather as w2
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
WHERE w2.temperature > w1.temperature;
SELECT query_name,
       ROUND(AVG(rating * 1.0/position),2) as quality,
       ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END ) * 100.0/ COUNT(*) ,2) as poor_query_percentage
FROM Queries
Group by query_name;       

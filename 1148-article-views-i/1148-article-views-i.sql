SELECT distinct author_id as id
FROM Views as a
where author_id = viewer_id
order by id;

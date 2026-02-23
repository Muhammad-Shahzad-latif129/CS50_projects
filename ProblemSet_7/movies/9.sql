-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
-- If a person appeared in more than one movie in 2004, they should only appear in your results once.

SELECT DISTINCT person_id AS ID, name FROM people 
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id WHERE 
year = 2004 ORDER BY birth;
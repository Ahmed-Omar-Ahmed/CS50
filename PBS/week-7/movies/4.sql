select count(movies.id) from movies
join ratings on movies.id=ratings.movie_id
and ratings.rating=10;
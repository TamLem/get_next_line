***
### <em>get_next_line<em/> - a "read line" function  
----
    
    
> ``char *get_next_line(int fd);``

The get_next_line() method helps to read just one line at a time, and it returns the first line from the file given. 

It will return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

The returned line will include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

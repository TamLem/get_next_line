# get_next_line
	- declare static buf
	- allocate BUFFER_SIZE to buf
	- Read to buff, cases :
    	- pos.newline < buf_size
        	- create substr till new line and return
        	- move rest to buf[0]
        	- fill back with \0
    	- pos.newline > buf_size

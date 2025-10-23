# A dummy script that counts all .sh files in the current directory

ls -1 | grep "\.sh$" | wc -l

# ls -1		: lists all files and directories by name, one per line.
# grep "\.sh$"	: Filters all files ending with .sh. In particular, '$'
#		  indicates line end and '\.' escapes the . character, i.e.,
#		  the actual '.' character
# wc -l 	: Counts words, counting each line (-l) as one word.

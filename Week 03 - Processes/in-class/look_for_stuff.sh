# Another dummy script looking for some stuff

for i in {1..5}; do
	fname="file_0$i" # Declare a string variable
	# Be careful when declaring variables to *not* use spaces,
	# since this will tell bash to treat your variable as a 
	# command! So, stick '=' to the variable's name!
	if [ -f $fname ]; then
		echo "File $fname exists!"
	else
		echo "File $fname does not exist!"
	fi
done

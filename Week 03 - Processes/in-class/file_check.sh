# Checks whether a file named 'test.file' exists or not.

if [ -f test.file ]; then
	echo "File exists!"
else
	echo "File does not exist!"
fi

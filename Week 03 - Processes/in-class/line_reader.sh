# A dummy script that

while read line; do
	if [[ $line == "quit" ]]; then
		echo "Bye!"
		break
	fi
	echo "You entered: $line"
done

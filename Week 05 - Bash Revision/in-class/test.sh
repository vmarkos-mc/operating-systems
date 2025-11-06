# Dummy backup utility
# $1: user provided directory

dir=$1 # Use a more descriptive name
for file in $dir/*.txt; do
	cp $file "$file.bak"
done

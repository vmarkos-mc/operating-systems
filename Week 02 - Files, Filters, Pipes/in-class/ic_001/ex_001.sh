# Draft half-baked solution for in-class exercise #001

# If no .special files exist, this will treat '*.special' as a plain string

for file in *.special; do
	lines=`wc -l $file` # Backticks perform command substitution
	words=`wc $file` # This is not just what we want
	echo "File: $file, lines: $lines, words: $words"
done

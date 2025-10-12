# Create some .imp files
for i in {1..5}; do
    touch "file_0$i.imp"
done

# Back them up
prefix="backup_"
for file in *.imp; do
    mv "$file" "${prefix}$file"
done
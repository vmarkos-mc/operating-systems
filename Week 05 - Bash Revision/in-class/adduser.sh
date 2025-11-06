# Dummy utility to add a new user with a set password

# This is useful for larger scripts, here we use semantic names
# just for demo.
username=$1
usercomm=$2

# You might want to first check if the user exists here...
# First, create a new user
useradd $username
# Then, add the user-provided comment
usermod -c "$usercomm" $username
passwd $username

# As a general note, when a string argument contains spaces, they are by
# default expanded, so usermod above, without "", would read each word
# as a separate argument - resulting to errors.

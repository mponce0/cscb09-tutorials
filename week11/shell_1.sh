# Create a shell script that backup your home-dir into a compress file somewhere else indicated by the user.
# You can either use cp or rsync.
# The destination of the backup will be given by a command line argument passed into the script.

if [ -z "$1" ]
then
      echo "Please enter a destination directory"
      exit 1
fi

zip -r $1/backup.zip /home/
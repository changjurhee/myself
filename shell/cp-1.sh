#! /bin/sh

formats=( "*.jpg" "*.mp4" "*.mov" "*.m4v" "*.mpg" "*.3gp" "*.png" )

for v in ${formats[@]};
do find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname $v -exec cp -af {} /Volumes/Backup/Note/ \;
done


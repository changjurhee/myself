#! /bin/sh

formats=( "*.jpg" "*.mp4" "*.mov" "*.m4v" "*.mpg" "*.3gp" "*.png" )

for v in ${formats[@]};
do find /Volumes/LG\ External\ HDD/사진정리/ -iname $v -exec cp -aR {} /Volumes/Backup/LG/ \;
done


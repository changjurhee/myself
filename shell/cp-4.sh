#! /bin/sh

formats=( "*.jpg" "*.mp4" "*.mov" "*.m4v" "*.mpg" "*.3gp" "*.png" )

touch 200801010000 start.txt
touch 200812312359 end.txt

for v in ${formats[@]};
do find /Volumes/LG\ External\ HDD/사진정리/ -newer start.txt -a ! -newer end.txt -iname $v -exec cp -aR {} /Volumes/Backup/LG/2008/ \;
done


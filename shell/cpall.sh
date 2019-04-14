#!/bin/sh
echo "Hello, world!"

find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.m4v’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.3gp’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.mp4’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname '*.MPG' -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.mov’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.jpg’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/오리/ -iname ‘*.png’ -exec cp -af {} /Volumes/Backup/ \;

find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.m4v’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.3gp’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.mp4’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname '*.MPG' -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.mov’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.jpg’ -exec cp -af {} /Volumes/Backup/ \;
find /Volumes/LG\ External\ HDD/사진정리/ -iname ‘*.png’ -exec cp -af {} /Volumes/Backup/ \;

find ~/.Trash/ -iname ‘*.png’ -exec cp -af {} /Volumes/Backup/ \;
find ~/.Trash/ -iname ‘*.jpg’ -exec cp -af {} /Volumes/Backup/ \;
find ~/.Trash/ -iname ‘*.mp4’ -exec cp -af {} /Volumes/Backup/ \;
find ~/.Trash/ -iname ‘*.mov’ -exec cp -af {} /Volumes/Backup/ \;
find ~/.Trash/ -iname ‘*.m4v’ -exec cp -af {} /Volumes/Backup/ \;

find ~/Pictures/ -iname '*.jpg' -exec cp -af {} /Volumes/Backup/ \;
find ~/Pictures/ -iname ‘*.mp4’ -exec cp -af {} /Volumes/Backup/ \;
find ~/Pictures/ -iname ‘*.mov’ -exec cp -af {} /Volumes/Backup/ \;
find ~/Pictures/ -iname ‘*.mpg’ -exec cp -af {} /Volumes/Backup/ \;
find ~/Pictures/ -iname ‘*.m4v’ -exec cp -af {} /Volumes/Backup/ \;

find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.m4v’ -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname '*.3gp' -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.mp4’ -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.MPG’ -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.mov’ -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.jpg’ -exec cp -af {} /Volumes/Backup/ \;
find /Users/changjurhee/Samsung/SmartSwitch/Backup/ -iname ‘*.png’ -exec cp -af {} /Volumes/Backup/ \;

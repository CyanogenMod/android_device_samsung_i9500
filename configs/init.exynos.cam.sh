#!/system/bin/sh

echo "0" > /data/CameraID.txt
chown media:audio /data/CameraID.txt
chmod 600 /data/CameraID.txt

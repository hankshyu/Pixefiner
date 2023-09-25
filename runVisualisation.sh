for i in {0..3}
do
python3 utils/visualise_pixel.py output/test$i.txt visualise/test$i.jpg
done

ffmpeg -framerate 1 -i ./visualise/test%d.jpg -c:v libx264 ./visualise/pixelHistory.mp4

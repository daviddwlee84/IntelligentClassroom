pgrep -f ffserver ffmpeg | xargs kill -9
# another way
# kill -9 `pgrep -f ffserver ffmpeg`
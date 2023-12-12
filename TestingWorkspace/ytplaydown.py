import re
from pytube import Playlist
import ssl
ssl._create_default_https_context = ssl._create_stdlib_context
playlist = Playlist('https://www.youtube.com/playlist?list=PLYl6RXwuT7UU6xeSBHDmTjbSQNqc7EhQP')

for video in playlist.videos:
    print('Downloading : {}'.format(video.title))
    video.streams.\
        filter(type='video', progressive=True, file_extension='mp4').\
        order_by('resolution').\
        desc().\
        first().\
        download()
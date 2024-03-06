from pytube import YouTube
import ssl
ssl._create_default_https_context = ssl._create_stdlib_context
try:
    # Ask the user to input the YouTube URL
    url = input("Enter the YouTube URL: ")
    
    yt = YouTube(url)
    
    print("Title:", yt.title)
    print("Views:", yt.views)

    # Get the highest resolution stream
    #yd = yt.streams.get_highest_resolution()
    yt.streams.filter(res="1080p").first().download()
    
    # Download the video to the current directory
   
    
    print("Download complete.")
except Exception as e:
    print("An error occurred:", str(e))

# requests is installed on the server in python3. Use pip to install it in your 
#   system if necessary. Or remove it if using another module
import requests


class VideosClient:

    def __init__(self, base_url = 'http://localhost:57300/'):
        self.base_url = base_url

    # (1pt) get and return a list containing all videos
    def get_all_videos(self):
        pass

    # (2pt) get and return a single video
    #       return None if no video with the provided uid exists
    def get_video(self, uid):
        pass

    # (3pt) create a video and return the created representation returned by server
    #       raise an exception if the server provides a 400 Bad Request
    def create_video(self, video):
        pass

    # (3pt) update a video and return the created representation returned by server
    #       raise an exception if the server provides a 404 Not Found error
    def update_video(self, video):
        pass # 

    # (1pt) delete a video with the corresponding uid
    def delete_video(self, uid):
        pass



if __name__ == "__name__":
    # write your test code here
    # anything written here will not be graded, but it will make it easier for you
    #   to grab the created uids to use to test the various functions

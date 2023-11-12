
#!/usr/bin/env python

import requests as req
import json

# requests is installed on the server in python3. Use pip to install it in your
#   system if necessary. Or remove it if using another module
class VideosClient:

    def __init__(self, base_url = 'http://localhost:57300/'):
        self.base_url = base_url

    # (1pt) get and return a list containing all videos
    def get_all_videos(self):
        res = req.get(self.base_url + 'videos')
        text = res.text
        return json.loads(text)

    # (2pt) get and return a single video
    #       return None if no video with the provided uid exists
    def get_video(self, uid):
        res = req.get(self.base_url + 'videos/' + uid)
        if res.status_code == 200:
            text = res.text
            return json.loads(text)
        else:
            return 'None'

    # (3pt) create a video and return the created representation returned by server
    #       raise an exception if the server provides a 400 Bad Request
    def create_video(self, video):
        res = req.post(self.base_url + 'videos/' + video)
        if res.status_code == 200:
            return 'video created'
        else:
            return 'video not created'

    # (3pt) update a video and return the created representation returned by server
    #       raise an exception if the server provides a 404 Not Found error
    def update_video(self, video):
        res = req.put(self.base_url + 'videos/' + video)
        if res.status_code == 200:
            return 'video updated'
        else:
            return 'could not update video'

    # (1pt) delete a video with the corresponding uid
    def delete_video(self, uid):
        res = req.delete(self.base_url + 'videos/' + uid)
        if res.status_code == 200:
            return 'Success'
        else:
            return 'Not Sucessful'


if __name__ == "__main__":
    vc = VideosClient()
    print('=' * 40, end = ' ')
    print('getting all videos', end = ' ')
    print('=' * 40)
    print(vc.get_all_videos())
    print('=' * 40, end = ' ')
    print('finished getting all videos', end = ' ')
    print('=' * 40)
    #print()
    print('-' * 80)
    #print()
    uid = ['ba704f75-9591-49b1-bf84-87e3b225bfd0', '5051d46c-d3cd-4fbd-916c-172c44b14dfc', 'a']
    print(vc.get_video(uid[0]))
    print('=' * 80)
    print(vc.get_video(uid[1]))
    print(vc.get_video(uid[2]))
    print(vc.delete_video(uid[2]))
    # write your test code here
    # anything written here will not be graded, but it will make it easier for you
    #   to grab the created uids to use to test the various functions

import requests
import json

# requestSugangBasket for cart
url = 'http://for-s.seoultech.ac.kr/JSONMain'
data = {'SUBJ_CD': '109416,109479,109817',
        'LECT_NUMB': '11001,41001,21001',
        'fsp_action': 'MainAction',
        'fsp_cmd': 'requestSugangBasket'}

#requestSugang for individual classes

# yunjay uid 7043475455645921533
# JSESSIONID should be refreshed
headers = {'Cookie': 'ipmsperf_uuid=-5083149224969333533; JSESSIONID=748v7XjEzsOuZgjQ9D2XIGpe4I3OIexW1AAi0nTVRJuWg91k4iYgUn2WNIoP0WsU.total2_servlet_engine4',
           'Origin': 'http://for-s.seoultech.ac.kr',
           'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.97 Mobile Safari/537.36',
           'Content-Type': 'application/json; charset=UTF-8',
           'Accept': 'application/json, text/javascript, */*; q=0.01',
           'Referer': 'http://for-s.seoultech.ac.kr/view/sugang.jsp',
           'X-Requested-With': 'XMLHttpRequest'}
#cookie, useragent, subj code, lecture number

while True:
    response = requests.post(url=url, data=json.dumps(data), headers=headers)
    j1 = response.json()
   
    print("j1: "+j1['ErrorMsg'])
    if (j1['ErrorCode'] == '0'):
        break
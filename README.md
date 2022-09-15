🧥피팅해조👚



##  과학기술정보통신부 주최 / 2022 공개S/W 개발자 대회

시연 영상 :

발표 자료 :



##  개요 

스마트 피팅로봇은 다양한 스팩트럼의 인체치수가 입력되면, H/W적으로 해당 치수에 맞는 마네킹을 구현합니다.



##   Contributer

|     팀원      |                역할                |
| :-----------: | :--------------------------------: |
| 😝정다혜(팀장) | 문서 담당 및 보고서 작성, 아이디어 |
|    😁유성환    |        기둥 및 조각 모델링         |
|    🥶이동희    |       아두이노 동작구현 코딩       |
|    😡이하은    |       아두이노 동작구현 코딩       |
|    😘최승환    |          랙, 모듈 모델링           |



##  제품 구상

####  01. 마네킹 기둥설계

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\기둥 전면.JPG" alt="기둥 전면" style="zoom:80%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\기둥 측면.JPG" alt="기둥 측면"  /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\기둥 후면.JPG" alt="기둥 후면" style="zoom:80%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\기둥 실물.jpg" alt="기둥 실물" style="zoom: 26%;" />

<기둥 정면>, <기둥 측면>, <기둥 후면>

####  02. 마네킹 조각 설계

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\조각 전체 사진.JPG" alt="조각 전체 사진" style="zoom: 67%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\조각 전체 사진2.JPG" alt="조각 전체 사진2" style="zoom:60%;" /><img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\조각 전체 후면.JPG" alt="조각 전체 후면" style="zoom:67%;" />

<조각 정면>, <조각 측면>, <조각 후면>

#####  02-1 조각과 랙의 연결부위

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\어깨2.JPG" alt="어깨2" style="zoom:80%;" /> 

<어깨에 랙과 연결될 부위를 결합한 사진>

####  03. 기어와 연결할 랙과 연결부위, 모듈 설계

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\250랙.JPG" alt="250랙" style="zoom: 55%;" /><img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\연결부위.JPG" alt="연결부위" style="zoom:80%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\모듈.JPG" alt="모듈" style="zoom:75%;" />

<250mm랙>, <랙과 조각 연결부위>, <랙이 들어갈 모듈>

####  04. 아두이노로 동작  구현

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\코딩\1.png" alt="1" style="zoom: 65%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\코딩\2.png" alt="2" style="zoom:65%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\코딩\3.png" alt="3" style="zoom:65%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\코딩\4.png" alt="4" style="zoom:65%;" /> <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\코딩\5.png" alt="5" style="zoom:65%;" /> 

<video src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\KakaoTalk_20220915_100300223.mp4"><style="zoom:10%;"/video>

####  05. 앱인벤터로 인터페이스 제작

​                                <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\앱인벤터.png" alt="앱인벤터" style="zoom:50%;" />                              <img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\인터페이스.png" alt="인터페이스" style="zoom:50%;" />  

##  기술 스택

![1](C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\1.JPG)

#####  - 작동 순서

1. 치수 입력
2. 무선 통신
3. 입력 받은 치수 저장
4. 저장된 데이터 불러오기
5. 초기화
6. 치수 조절

###  기둥과 모듈 결합

<img src="C:\Users\HP\OneDrive - 한국폴리텍대학\바탕 화면\ICT\캡쳐\KakaoTalk_20220914_183021717_03.jpg" alt="KakaoTalk_20220914_183021717_03" style="zoom:60%;" />
#include <ansi.h>
inherit ROOM;

string *room_long = 
({
//1
"在一望無際的沙漠哩，好像走到哪的景色都一模一樣，加上天氣
極為酷熱，在這裡多待一時半刻都是一種煎熬。似乎上天沒聽到你內
心的吶喊，殘酷的天氣依舊持續。\n",
//2
"滾滾的沙塵掩蓋\了前面的去路，讓你摸不清現在所在的地理位置
究竟是在哪，是往東還是向西，似乎沒有一個答案，現在唯一知的就
是，到底這場沙塵暴何時完結。。\n",});

string ROOM_LONG()
{
        return room_long[random(sizeof(room_long))];
}



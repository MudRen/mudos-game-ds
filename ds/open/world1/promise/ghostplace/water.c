#include <ansi.h>
inherit ROOM;

string *room_long = 
({
//1
"這裡看起來廣大的遼闊，風景讓人看起來，會覺得大自然的奧妙 
。你默默的聽到一些歌舞聲，你走了一陣子，你觀察了所有地方，還
是查不出歌曲是那來的歌曲聲音。\n",//2
"在此刻，身旁完全靜如止水，沒有任何的吵雜聲，就好像身在大
自然裡這麼的安祥寧靜，不過古人稱之為暴風雨前的寧靜，你無法預
知下一秒會發生什麼事，所以此刻內心感覺膽顫不已。\n",});

string ROOM_LONG()
{
        return room_long[random(sizeof(room_long))];
}

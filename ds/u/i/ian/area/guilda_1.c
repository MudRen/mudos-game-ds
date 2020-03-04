#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天梟聖殿"NOR);

 set("long",@LONG
這間巨大的石室中央有一座天梟雕像, 一群天梟教眾團團圍著雕像跪
拜, 一個個口中唸唸有詞, 心靈的契合使他們能夠在彼此不溝通的情形下
, 尚能做出整齊畫一的動作, 石室中迴盪著他們虔誠的禱告, 激盪了你的
心情, 在石室更深處, 有一個坐椅, 看來是天梟教主所坐, 這裡看來是天
梟重大集會的地點. 
LONG
    );
 set("exits",([ "south":__DIR__"guilda",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

#include <room.h>
inherit ROOM;
void create()
{
 set("short","左側平臺");
 set("long",@LONG
從這邊往西邊望去, 可以清楚的看到百年來都一直
屹立不搖的向天關, 關上有幾隻不知道是什麼鳥在盤旋,
著, 關外大漠之上似乎已經有好幾年沒有戰爭了.
LONG
    );
 set("exits",(["east":__DIR__"inroom58"]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

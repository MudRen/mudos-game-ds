#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹叢中");
 set("long",@LONG
你的南邊有些奇怪的聲音, 最好是不要過去比較安全.
你的西邊就是向雲堂了, 要回去向雲堂得先越過一條小河. 
LONG
    );
 set("exits",(["south":__DIR__"outroom14",
               "westup":__DIR__"inroom20",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
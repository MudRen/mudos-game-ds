#include <room.h>
inherit ROOM;
void create()
{
 set("short","北市街");
 set("long",@LONG
這裡是廣場北方的街到, 沿街有賣些小吃, 精品的
攤位, 小販都笑嘻嘻的看著你, 好似希望你買些他們的
東西, 不過價錢好像有點....
LONG
    );
 
 set("exits",(["north":__DIR__"village13",
               "south":__DIR__"village4",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

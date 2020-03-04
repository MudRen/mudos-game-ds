#include <room.h>
inherit ROOM;
void create()
{
 set("short","賓客休息室");
 set("long",@LONG
這邊是給一般江湖人士來到向雲堂時接洽之用, 桌上
有壺茶水, 你可以自己飲用, 裡面有位較高階的侍僕, 你
可以和他打聽一些事情. 旁邊有兩三位休息的客人.
LONG
    );
 set("exits",([ "west":__DIR__"outroom1",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"變臉工作站"NOR);

 set("long",@LONG
你發現這裡除了一個大大的文件櫃和一個沙發以外一無所有, 
你不禁疑惑這裡有人用嗎?......
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "old":"/open/world1/meetroom",]));



 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

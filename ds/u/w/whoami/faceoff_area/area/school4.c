#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"騰空書院二樓"NOR);

 set("long",@LONG
恭喜你終於通過了迷宮, 騰空書院已經沒有什麼可以教你的
東西了, 希望你已後能夠行俠仗義, 遵守Ds的規則, 成為一個令
人敬佩的好玩家! 切記! 切記! 

LONG
    );
 set("exits",([ "in":"/open/world1/tmr/area/inn_2f", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
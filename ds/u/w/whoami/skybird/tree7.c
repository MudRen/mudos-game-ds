#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","小徑");
 set("long",@LONG 
眼前土地一片荒蕪, 大概是右手邊那棵高聳穿雲的大樹遮蔽
了陽光, 使得這裡寸早不生, 但是也因為這棵大樹的庇佑, 讓生
活在這裡的小動物能免於飛禽的攻擊.
LONG
    );
 set("exits",([
     "south":__DIR__"tree5",
     "enter":__DIR__"house",
             ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("enter","破爛的木門","out",DOOR_CLOSED,"nokey");
}



#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"木屋"NOR);
 set("long",@LONG
進入到這才能算進到天梟冶藥一派, 你發現這裡和天梟武
學一派十分不同, 這裡明顯就是一間臨時搭建的木屋, 什麼裝
飾也沒有, 往外是你走進天梟的路, 在北邊隱約有讀書聲傳來.
LONG);
 set("exits",([ "out":__DIR__"pill1",
                "northeast":__DIR__"pill3",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("out","小木門","enter",DOOR_CLOSED,"nokey");
}           



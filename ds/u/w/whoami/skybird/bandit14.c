#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","財寶室");
 set("long",@LONG 
這裡就是十萬山寨存放財寶的地方了, 四周圍並沒有什麼值得
注意的機關或是拿著刀槍的守衛, 只有那為了照明而點燃的油燈.
在油燈的映照之下, 周圍的寶箱顯得格外的引人注目. 
LONG);
 set("exits",([ 
                "out":__DIR__"bandit11", 
    ]));
 set("objects", ([
                __DIR__"obj/red_box" : 1, 
                __DIR__"obj/orange_box" : 1,
                __DIR__"obj/yellow_box" : 1,
                __DIR__"obj/green_box" : 1,
                __DIR__"obj/blue_box" : 1,
                __DIR__"obj/indigo_box" : 1,
                __DIR__"obj/purple_box" : 1,
    ]));
 set("no_recall",1);
 set("no_clean_up",0);
 set("light",1);
 setup();

}

void door_closed()
{
   this_object()->delete("exits/out");
   tell_room(this_object(), HIW"石門『碰』的一聲，突然被關上了•\n"NOR);
   return;    
}


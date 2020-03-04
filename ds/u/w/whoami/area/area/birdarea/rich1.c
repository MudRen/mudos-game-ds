#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","富宅大門");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪門前, 你面前是一扇巨大的
朱漆大門, 兩旁還有一對張牙武爪的石獅子, 在你腳邊有一排十
階的石階, 石階連接著大門•
LONG
    );
 
 set("exits",(["south":__DIR__"village15",
               "enter":__DIR__"rich2",
              ])); 
 set("objects", ([__DIR__"npc/dog" : random(3),
               ]));
 setup();
 create_door("enter","朱漆大門","out",DOOR_CLOSED,"nokey");
}        

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("watchdog",environment(me)) && 
     ( (dir=="enter") ))
       {
        message_vision(HIY"\n看門狗對$N狂吠了幾聲，看來不解決牠是進不去了•\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}


inherit ROOM;
inherit DOOR;
#include <room.h>
#include <ansi.h>

void create()
{

   set ("short", HIM"天妖山洞"NOR) ;
   set ("long", "這裡就是天妖山洞，相傳有邪天妖被大神封印在此...地上似乎有的暗門•\n") ;
;
        set("exits", ([ /* sizeof() == 3 */
                    "east":__DIR__"infinite9.c",
                    "down":__DIR__"skyevil1.c",
]) ) ;

















       

        set("no_clean_up", 0);
        set("light", -1); 
        set("objects",([
                   __DIR__"guardwolf" : 1,
                 ]) );

        setup();
create_door("down",HIM"天妖門"NOR,"up",DOOR_LOCKED,"skyevilkey");
}




















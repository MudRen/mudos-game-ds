#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{



set("short", HIY"禁地"NOR);
set("long", @LONG
這裡是凌雲寺的禁地，有許多凌雲的弟子在那邊看守著，為的是要防止        
關在裡面的破戒僧出來鬧事，聽看守的弟子說，裡面有許多猛禽在內，聽說
是裡面的破戒僧的怨氣製造出來了的，這猛禽兇狠無比，難怪方丈要派出寺
中武藝高超的和尚來看守•        
LONG

  );      

 set("no_clean_up", 0);

 set("exits", ([ /* sizeof() == 1 */

 "south" : __DIR__"a2",
]));

       
set("objects",([

   "/u/k/kakasi/npc/b1" : 1,
]) );

        set("outdoors", "land");



        setup();

        replace_program(ROOM);

}


     





inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"玉笥山"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    剛剛在山腳下時陽光明媚，到達山上時卻細雨瀟瀟，眼前的玉笥山
蔥蘢疊翠，被悠悠的汨羅江環抱著，瑩瑩然像塊翡翠。往西北看去可看
到一亭子坐落汨羅江畔，想必便是那「獨醒亭」了。

LONG
        );
    set("exits",([
 "westdown" : __DIR__"room06",
 "eastup" : __DIR__"room09",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}


#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL"牛皮蒙古包-內屋"NOR);
  set("long", @LONG
這裡是一間小小的蒙古包，四週佈置的十分簡潔，在一旁的角落
放著數隻不同顏色的牛角飾物。
LONG
);
  set("exits", ([
  "south" : __DIR__"room33",
]));
  set("no_clean_up", 0);

        set("objects", ([ /* sizeof() == 1 */
"/open/world1/tmr/cow_area/tombstone.c" : 1,
]));
    
  setup();
  replace_program(ROOM);
}

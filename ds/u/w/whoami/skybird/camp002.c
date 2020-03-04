#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
        set("short", "固山寨大門");
        set("long", @LONG
固山寨得名是因為這座寨子建在一座小山頭上，與其說是小
山，不如說是一座岩石丘陵，而且寨子�堶惘酗@眼水量極大的泉
水，順著山勢流下。
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"camp001",
  "enter" : __DIR__"camp003",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        create_door("enter","寨門","out",DOOR_CLOSED,"nokey");
}


#include <path.h>
inherit ROOM;

void create()
{
        set("short", "南大街");
        set("long", @LONG
你正走在一條廣大熱鬧的街道，街上行人川流不息，大多是趕往南邊
的市集所在，朝天樓就座落在往北邊的大街不遠處。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
              "north" : __DIR__"street5",
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}



#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "地下城南走道");
        set("long", @LONG
四周的空氣出乎你意料之外的清新，看來剛剛那幾根霸道的電子柱還
真有些功用勒，從西邊電子機器的吆喝聲中不難聽出，這個附屬城市已經
算是歷史久遠了，連機器人都是2042年出產的中古型機器人，四周冷冷清
清的，不曉得這裡的居民都到哪裡去了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
 "west":__DIR__"weapon.c",
   "north":__DIR__"sec3.c",
    "south":__DIR__"sec1.c",]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("no_clean_up", 0);

        setup();
 create_door("south","電磁門","north",DOOR_OPENED,"nokey");
}



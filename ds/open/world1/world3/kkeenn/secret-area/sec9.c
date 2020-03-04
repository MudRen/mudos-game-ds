#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城西端");
        set("long", @LONG
剛回顧四周，有股復古式的美國西部牛仔氣息存在著，木屋俊馬，人
群的嘻鬧聲，給人一股與剛才截然不同的感覺， Secret City果然像是一
座歷史古城，有著各式各樣的氣氛，每走一步就給人一種截然不同的感覺
，這......應該是早在 150年前最流行的夢幻程式架構了吧？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec8.c",
     "north":__DIR__"equip.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}

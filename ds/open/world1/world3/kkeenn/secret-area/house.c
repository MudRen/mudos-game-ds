#include <room.h>
inherit ROOM;
void create()
{
        set("short", "城主之間");
        set("long", @LONG
這裡是地下城城主的家，你看著在頭上華麗的吊燈，散發優雅的光
線令人感受出一股溫暖的感覺，在你前面的巨大沙發上坐著一位年事
已高的老人家，你看著他，突然一陣莫名的感傷湧上心頭。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec12.c",
     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/king.c"    :1,
]));

        setup();
        replace_program(ROOM);

}

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ä���");
        set("long", @LONG
����Mob(NPC)���X�o�I�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "down":__DIR__"sec12.c",
     "east":__DIR__"sec11.c",      "west":__DIR__"sec3.c",
     "north":__DIR__"sec8.c",
     "up":__DIR__"min1.c",
     "south":__DIR__"equip.c",     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);
}


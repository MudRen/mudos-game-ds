#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�q�|�J�f");
        set("long", @LONG
�o�̬O�a�U���q���q�|���ߤ@�D���A�ө����q�u����ۤp���A�ݰ_
�ӤQ�����ּ֡C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
//     "enter":"/u/t/truewind/Minetown/area/minetown.c",
     "south":__DIR__"sec7.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}

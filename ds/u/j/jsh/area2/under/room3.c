#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�o�q�����G�V���V���A�Y���Ψ�Ǫ�����n���n�§A�ˤU�����A
�Q�۷Q�۬�M���F��I�F�A�@�U�A�������򪽽ݡA�]�U���o�Y�W����
���F�g�A�֨B���e���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room2", 
  "north" : __DIR__"room4",
  "southwest" : __DIR__"room_3",
  "southeast" : __DIR__"room-3",]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/boots-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


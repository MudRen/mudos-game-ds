#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�A����B�쪺����,�A�uı�o�U�ӷU�N�F,�S�Q�^���~���a��,
���A�S�Q��p�G�^�h���ܤS�|�ܼ�,�A�ܥ٬ު����b�o�̷Q�F�@
��,�M�w�٬O�~�򪺩��e��,�@���}�]���`�B
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" :"/u/t/tako/area/room~9.c",
  "east" :"/u/t/tako/area/room~7.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/woman.c" : 1,
]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}







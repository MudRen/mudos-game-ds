#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�A��F�}�]�������A���~���q�n��@�P�F�A�r�~�����s�n���A������
�@���r���A�A�ݨ�̭��n�����ӤH?
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/t/tako/area/room~2.c",
  "north" :"/u/t/tako/area/room~4.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/redhone.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}


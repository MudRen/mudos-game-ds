#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�A�֨���F�}�]�����Y,�A�������٬O���_���b���r�~�����s�n��
�@�P,�A�S�ݨ�̭��n�����ӤH?���o���A�M���a��L�C
LONG
);
   set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/t/tako/area/room~3.c",
  "enter" :"/u/t/tako/area/room~5.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/sun.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();

}

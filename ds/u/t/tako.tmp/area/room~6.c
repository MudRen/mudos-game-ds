#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�o�̬O�}�]������,�A�Pı�U�ӷU�Y���F,�����֭n�����F�F,
�A���e�@��,�n���O�L��ɪ��s�},�e���n���]���H,���A�߸�
�����Ӽ�,"��"�M�D����
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" :"/u/t/tako/area/room~2.c",
  "west" :"/u/t/tako/area/room~7.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/axe man.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}





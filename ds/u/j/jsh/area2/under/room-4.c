#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�Ө�o��O�@���Ƿt���p�ж��A�A�⤤�����u�n��������W����
ê�����A�u��ӫG�A�P��T�ت��Ŷ��A���㪺�`���P�|�P���j�ﵷ��
�A�u�Q�������}�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room4",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/gloves-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


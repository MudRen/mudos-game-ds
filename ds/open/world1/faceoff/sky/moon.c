// Room: /open/world1/faceoff/sky/moon.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"�s���̹D-�_�f�B"NOR);
        set("long", @LONG
�s���̹D���D������o�̴N�����F�A�A���U�O�@���`����
�����l���A��ԲD�n�B�צ~������¶�C�s�����묰�Q�j�۵M�_
�[���@�A���ֹD�G����X�s���A�a�������A�z���s�����몺
�����Ӧ��C
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"ten27",
]));
        set("outdoors", "land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


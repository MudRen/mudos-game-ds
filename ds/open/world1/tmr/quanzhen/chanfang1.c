// chanfang1.c �I��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�I��");
        set("long", @LONG
�o�̬O���u�Ч̤l�\��L�����I�СA�a�U���æa��ۤ@�ǼC�A��
���w�g�ï������F�A�����٬O�W�Q�z�G�A���u�̤l�m�\���ɭԡA�N��
�o�̨ӬD��L�b�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"chanfang2",
        ]));
        set("objects", ([
                __DIR__"npc/obj/gangjian" : random(3),
                __DIR__"npc/obj/gangdao" : random(2),
                __DIR__"npc/obj/tiejia" : random(2),
        ]));

	set("coor/x", -2750);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۫Τ�");
set("long",@LONG
�A�ݨ�A�����e���@��վv�a�a���ѤH, ���g�L�ǤH�f��
�۶�, �ڥ����|�N���e���ѤH�M�ǩ_�H���L�c�a�Q�b�@�_.
LONG
    );
 set("exits",([ "south":__DIR__"seacoun30",
		"north":__DIR__"seacoun32",
]));
 set("objects", ([__DIR__"../npc/lin" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            
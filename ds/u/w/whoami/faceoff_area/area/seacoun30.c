#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L���");
set("long",@LONG
�o�̴N�O�L�⪺��f�F, �A�ݨ�A���_��P�n��U���@��
�۫�, ��ӥ_��N�O�L�⪺���, �L�c�a, �����, �ӫn��h
�O�L�����M�Ϊ��ײ�t.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun29",
		"north":__DIR__"seacoun31",
		"south":__DIR__"seacoun33",
	    "east":__DIR__"seacoun37",
]));
 set("objects", ([__DIR__"npc/thief" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            
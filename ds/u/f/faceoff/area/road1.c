#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
�o�O�@���q�Ѧ��q��Q�U�j�s�M�F�_�A�L���F�_�a�Ϫ�
�p��, �����n�ʨ�꦳���|���h���n, �����`�ɫ�Өө���
���H��]���ִN�O�F.
LONG
    );
 set("exits",([ "southwest":"/open/world1/acme/area/pool.c",
		"north":__DIR__"road2",
]));
 set("objects", ([__DIR__"npc/road_vendor" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             

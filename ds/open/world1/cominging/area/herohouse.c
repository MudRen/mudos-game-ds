#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "�^�����Υ~");
	set("long",@LONG
�o�̬O�B�F�������v����W���^�����Υ~�A�b�o�̦��\�\�h�h���X
�ӡA�䤤���@���S�O������A�]�S�O���j�A���j���N�O��b���a�L�W�^
�����ӸO�F�A�b�o�̦��@�y�^�����J��(statue)�C
LONG
	);
	set("exits", ([
  "north" : __DIR__"beast3.c",
  "enter" : __DIR__"herohouse1.c",
]));
	create_door("enter","�}�¦˪�","out",DOOR_CLOSED);
	set("objects", ([
  __DIR__"npc/hero_statue" : 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	set("outdoors","land");
	setup();
}

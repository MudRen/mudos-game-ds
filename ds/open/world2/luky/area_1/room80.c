// Modify with AreaMaker1.0
// Room80.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","�j���");
	set("long", @LONG
�o�̬O�@���j���A�A���P�򳣬O���ν��\�����C���褣�ɶ�
�Ӥ@�}�}���F���λ��n�A�A����n�����Y��h�A�ݨ���_�䦳�@��
�@�K����L�A���䤣���B�٦��@�Ӥp����C
LONG
	);
	set("exits", ([
		"north": __DIR__"room70",
		"west": __DIR__"room79",
		//"bridge" : LUKY_NOW+"test/room3",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}


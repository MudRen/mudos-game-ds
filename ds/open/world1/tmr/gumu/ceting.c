// ceting.c ���U
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
	set("short", "���U");
	set("long", @LONG
�o���O�j�Ӫ����U�A�K�ʱo�Y�Y���A�S���@�����_�ءC�b���t��
�O���U�A�����ݲM���U�������]�C
LONG	);
	set("exits", ([
		"east"  : __DIR__"mudao20",
		"north" : __DIR__"mudao19",
		"south" : __DIR__"mudao23",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

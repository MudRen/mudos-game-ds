// mishi1.c �K��
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�o���O�j�Ӥ����K�ǡA�|�P�K���z���A�A�u��ɵ��٤W���t���O��
�ӫj�j�����V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X���ƬO�����A�A
���H�q����X�@���_�ءC
LONG	);
	set("exits", ([
		"out"   : __DIR__"bianhou",
		"north" : __DIR__"mishi2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

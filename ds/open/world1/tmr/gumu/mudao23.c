// mudao23.c �ӹD
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�ӹD"NOR);
	set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
LONG	);
	set("exits", ([
		"north" : __DIR__"ceting",
		"south" : __DIR__"lingwu",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
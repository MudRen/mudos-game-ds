// mudao02.c �ӹD
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
		"east"  : __DIR__"qianting",
		"west"  : __DIR__"xiuxishi",
		"south" : __DIR__"mudao03",
          "northwest" : "/open/world1/moonhide/area/masterroom", // ���L tmr 2006/10/23
          "southwest" : "/open/world1/moonhide/area/master2room", // �p�s�k tmr 2006/10/23
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/gumu/anhe2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"�t�e"NOR);
	set("long", @LONG
��ӳo���O�@���a�U�t�e�A���B���n�w�O�F�F�A�n�շ����b�H�C�A
�}�U�@�B��šA�K�����y���R�|��C����y�����Ӧۦ�B�A�󤣪��q��
���C�C�C�A�w�Pı���պ��w�A�a�պ����C
LONG	);

	set("exits", ([
          "northup"  : __DIR__"caodi",
		"westdown" : __DIR__"qianliu2",
	]));
	set("no_clean_up", 0);
	setup();
    replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
	if (dir == "northup")
	{
		write(HIW"\n�A�X�o�}�ӡA�j���{ģ�A�@�ɤ������M�C���}���C\n"NOR);
	}
	return ::valid_leave(me, dir);
}

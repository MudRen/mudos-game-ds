// Room: /d/gumu/shishi5.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"�۫�"NOR);
	set("long", @LONG
�A��Mı�o���e�@�G�A�e��۫ǳz�L�Ӥ@���L�z�����A���F�A�@��
�Ʊ�C���٬O�uť�������ǨӧA�}�B���^���A�ſ������Pı�ϧA�ߤ��u
�����ߡA�ƦܧѰO�t�W�C�|�P�p���I�M�L�n�C�u��a�N���e��C
LONG	);
	set("exits", ([
		"west"  : __DIR__"shishi4",
		"enter" : __DIR__"lingshi",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

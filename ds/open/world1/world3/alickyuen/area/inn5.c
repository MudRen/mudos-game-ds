// Room: /u/a/alickyuen/area/inn5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�DSOFT�ICorridor"NOR);
	set("long", @LONG
�o�̬O�o�����]���a�U�G�Ӫ����Y�A�G�ǳ��O�@�ǵ��ȤH���]�I�A�N
���_�䨺���𶢫ǡA�ѤѤ]���ܦh�H�b�ɥΡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"inn2",
    "north" : __DIR__"inn7",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

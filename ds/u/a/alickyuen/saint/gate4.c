// Room: /u/a/alickyuen/area/gate4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�IWest"NOR);
	set("long", @LONG
�o�̬OSaint�����@���D���A�|�B�����ҨS������S�O�A�ӧA�S���M��
�@���h�|�q�����̡C���A�ݨ��ܦh�H���ۤ@�i�G�i����橹���䨫�h�A��
�_�Ө��ǬO�Ȧ�Ϊ��ѥ[���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst19",
  "east" : __DIR__"dst16.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

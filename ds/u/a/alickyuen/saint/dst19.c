// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�IWest"NOR);
	set("long", @LONG
��̫�A�A�٬O���ܤH�s�ӬݬݡA��Ӧb�o�̪������B�O�@���Ȧ��
�C�ܦh�H�b�ƶ��n�O�h�Ȧ�A�ϳo���ܱo�H�ӤH���A�t�A���I��Q�h�M�H
�̤@�_�ƶ����W�ѥ[�o�����j�Ȧ�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  // "west" : "/u/s/steps/area/py/gate1",
  "east" : __DIR__"gate4",
]));

        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));

   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/s/slency/area/ugelan/royalty2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�Ӯc����"NOR);
	set("long", 
"�o�̬O�Ӯc�����j�U�A���O���q�H�i�H�i�o�Ӫ��A�o�̪����C�Q��\n""���ءA���e�觤�ۨ���۰��Q���H�A���䯸�۫ܦh�ͽáA�A�Q�o���\n""���ӴN�O�վB����������P�ӦZ�F�C\n"
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"royalty3",
]));
	set("no_clean_up", 0);
set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/king" : 1,
 __DIR__"npc/queen" : 1,
 __DIR__"npc/guard3" : 4, 
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}

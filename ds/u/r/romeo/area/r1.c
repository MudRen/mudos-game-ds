// Room: /u/k/king/area/r1.c

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIR "�԰�"HIY"�ӳ�"NOR"-���k�߸�");
	set("long", @LONG
�o�O�@���s�����p���A���O��^���`���H�N�A�|�P�R���F�����A���M
�q�ѤW�����@���H�Y�A���A�P��򰩮��M�A�S����O�٬O�����}�a�C�o��
���O���M�H�i�H�Ӫ��C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r2",
  "south" : __DIR__"r2.c",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bat" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

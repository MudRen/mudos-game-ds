// Room: /u/s/sonicct/area/road11.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�����F�����ߡA�A�o�{�o�̦�����p���A�q�����P���a��C
�A��M�b�n�_�ߤ��U���b�o�̡A�ݬݨ�����p���O�q�h���̪��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road10",
  "north" : __DIR__"road15",
  "west" : __DIR__"road12",
//  "south" : __DIR__"road14",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}

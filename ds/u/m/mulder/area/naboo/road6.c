// Room: /u/s/sonicct/area/road6.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�b�o�̬ݦV�_��A�i�H�ݨ�@�y�������Ӯc�C�o�̪��u�ä�
���e��[�h�A�ݨӥH�����������J�h����O�@�����ơC�ӫn��N
�i�H���}�Ӯc���d��A�쥫���ߥh�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate2",
  "south" : __DIR__"road5",
]));
		 set("objects",([
 	 __DIR__"npc/police":2,
 ]));

	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

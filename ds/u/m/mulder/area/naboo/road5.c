// Room: /u/s/sonicct/area/road5.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̶}�l�ݩ�Ӯc���d��A�u�ä����b�A���Ǩ��L�C�O�A��
�@�دS�O���Pı�C���F���i�H�쥫���A�ʶR�A�һݪ����~�C����
�i�H�q�����C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road17",
  "west" : __DIR__"road16",
  "north" : __DIR__"road6",
  "south" : __DIR__"road4",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}

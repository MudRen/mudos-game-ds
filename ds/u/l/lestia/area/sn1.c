// Room: /u/l/lestia/area/sn1.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L");
	set("long", @LONG

�A���i�F�@�y�j�Ѫ��˪L�̡A�|�P�����@�K�B�������ƦC�ۡA�|�P�O
�@�������۪����H�A�A�o�{�ۤv�w�g�g���F��V�A�|�P�w�R���F�A�e������
�����F�n�X���A�u�����D�n�����@���H

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"map_7_7",
  "east" : __DIR__"sn5",
  "south" : __DIR__"sn2",
  "north" : __DIR__"sn3",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

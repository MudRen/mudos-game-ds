// Room: /u/l/lestia/area/sn22.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG

�A���i�F�@�y�j�Ѫ��˪L�̡A�|�P�����@�K�B�������ƦC�ۡA�|�P�O
�@�������۪����H�A�A�o�{�ۤv�w�g�g���F��V�A�|�P�w�R���F�A�e������
�����F�n�X���A�u�����D�n�����@���H

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sn5",
  "north" : __DIR__"map_12_6",
  "west" : __DIR__"sn5",
  "south" : __DIR__"sn5",
]));
	set("world", "undefine");
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

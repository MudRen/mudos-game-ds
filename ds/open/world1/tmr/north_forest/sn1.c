// Room: /open/world1/tmr/north_forest/sn1.c

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
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sn2",
  "northwest" : "/open/world1/tmr/goat_maze/maze1",
]));
	set("current_light", 5);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

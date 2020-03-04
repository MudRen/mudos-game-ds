// Room: /open/world1/tmr/north_bar/s6.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̪��a���٬O����Ʒƪ��A������S���e�����Y���F�A��
�O�o�̪��a�����G�`�`�b�_�ʡA�ӥB�X�G�S����L�C�����|���|
��@�b��M��Ӭ}���U�ӡE�E
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s5",
  "east" : __DIR__"s14",
  "north" : __DIR__"s7",
  "west" : __DIR__"s13",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

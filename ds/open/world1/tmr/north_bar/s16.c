// Room: /open/world1/tmr/north_bar/s16.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̦��G�Z�w�R�a�A������N�S�����F�C���O�@�ˬO���Ǫ�
�b�]�Ӷ]�h�A�ӥB�a���٫���n�̵ۡA���H�Pı�Q�����w�A�|��
�|����@�b��M��Ӭ}���U�ӡE�E
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s13",
  "east" : __DIR__"s7",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

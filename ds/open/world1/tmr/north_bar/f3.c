// Room: /open/world1/tmr/north_bar/f3.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�}��");
	set("long", @LONG
�o�̪��a�W�Q���W�Y�����A�ӥB�S�Q���U���A�a�W���O�d�g
���䳣�O���ťۡC�e�������n�������~���ʪ�����A�ݵۦa�W��
�}�L�A���A�q����쩳�O����Ǫ�...
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"f4",
  "northwest" : __DIR__"f1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

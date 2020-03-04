// Room: /open/world1/tmr/north_bar/s5.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̬�M�]�X�ư����~�A�}�l�o�Ʀ����ç����A�I���A����
���ӹL�ӡA�[�W�a�W���d�h�a�A���A����ʧ�[�������G�F�A��
���D�O�_�ٯ�X���h�E�E
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s2",
  "east" : __DIR__"s10",
  "north" : __DIR__"s6",
  "west" : __DIR__"s9",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

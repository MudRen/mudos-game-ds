// Room: /open/world1/wilfred/meadow/room33.c

inherit ROOM;

void create()
{
	set("short", "[33m���ֻX�j�][0m");
	set("long", @LONG
�o�̬O�@���p�p���X�j�]�A�|�g�G�m���Q��²��A�b�@�Ǫ�����
��ۼư����P�C�⪺���������A���G�O�q�������W���U�Ӫ����A�j�p
���@�A�䤤�̤j�����k�l�p�L��ʪ��C�t�~���F�@�Ǥ�`�ͬ��Ϋ~��
�~�A�A�]�L��L�ޤH�`�ؤ����C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/npc2" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room21",
  "north" : __DIR__"room36",
]));

	setup();
	replace_program(ROOM);
}

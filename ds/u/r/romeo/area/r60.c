// Room: /u/k/king/area/r60.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
�o�̴N�O�j���F�A�O�P���t�ҽk�A���䪺��ڨ観�s���Ϯת��W�l�O
�伵�o�̪���W�A�u�n�@�ˬݨӳo�̴N�|�ܦ��@����F�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�W�l" : "�@�ڨ�ۭ��ѯ��s���W�l�A���䪺�ͻH�O�ζ����һs�y�A�ݰ_�Ӭ۷�ȿ��A
�U�����}���ݰ_�Ӧn���@�ӧ��O�C
",
]));
	set("no_recall", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"49",
  "north" : __DIR__"r61",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pur" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

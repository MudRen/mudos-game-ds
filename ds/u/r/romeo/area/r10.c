// Room: /u/k/king/area/r10.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�o�̴N�O�������U��F�A����������ä��O���q�����A�ӥB�����n��
�O�ΤH�Y�䦨�o�A�ҨϥΪ��H�Y��b�L�k�p��A���Ǧ��줧���h���޻�b
�|�P�r�ޡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r9",
  "up" : __DIR__"r11",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

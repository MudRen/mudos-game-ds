// Room: /u/s/slency/area/ugelan/church3.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�@�y�۷�j���s���A�s���������@�y��j�����l�A���l����
���\�h�ե��J��Ӧ������N�~�A�M�o�@��L�ڪ��j�a�ŤѺc���F�@�T��
�R�۵M���ϵe�A�Ѧ����詹�F���O�s���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church2",
  "east" : __DIR__"church4",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

// Room: /u/a/acme/old_area/hills2.c
inherit ROOM;
void create()
{
	set("short", "���F��");
	set("long", @LONG
�A���B�b���F�����W�A�|�P�ɬO�F�l�A���[�A�Pı��n�����F��b��
�ۧA���}�A�A�ߤ����T���Q�_�O�_��e�ұ����H���޻�ӯ��R�F�A�A����
�ݰʵۡA�o�O���H�ӷX�A�٬O�֧����}���B���n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hills1",
  "west" : __DIR__"hills3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

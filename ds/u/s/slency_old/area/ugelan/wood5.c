// Room: /u/s/slency/area/ugelan/wood5.c

inherit ROOM;

void create()
{
	set("short", "�˪L�`�B");
	set("long", @LONG
�o�̸���L�a��y�L�G�F�@�ǡA���ǳ\�������q�����_�ؤ���F�L
�ӡA�o�̪����W���ܦW�㪺��������A�ݰ_�����ӬO�M�C���L���ҳy
�����A�̷Ӳ��񪺷s�¬ݨӡA�o�̩ҵo�ͪ��԰��Q�Ӧ����֦��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood6",
  "east" : __DIR__"wood4",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}

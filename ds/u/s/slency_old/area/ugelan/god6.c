// Room: /u/s/slency/area/ugelan/god6.c

inherit ROOM;

void create()
{
	set("short", "�Ӷ�");
	set("long", @LONG
���a���Ӧa���Q�����, �ݨӬO���M�H�b��z�����Y, ����]����
�H���L, ���ӳ��O���̪��~�����y�ӲM�z���a, �_�h���a�а�̭����H
���O���i�వ�쪺, ���F�n���K�ֶi�J�@�y�˪L�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"god4",
  "southeast" : __DIR__"god5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}

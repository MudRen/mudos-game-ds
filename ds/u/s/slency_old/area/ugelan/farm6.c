// Room: /u/s/slency/area/ugelan/farm6.c

inherit ROOM;

void create()
{
	set("short", "����~");
	set("long", @LONG
����o�̡A�A�i�H�ܲM�����ݨ��y�ݥߦb�C���W���վB�������A
�ݵ۰��q������A�A���T��Ħp�������򯫤u�A�Ѧ����観�@���p�T��
�A�ݨӬO���񪺲��A�ҩ~���a��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"farm7",
  "south" : __DIR__"farm3",
  "east" : __DIR__"farm5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}

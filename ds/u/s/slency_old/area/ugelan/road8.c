// Room: /u/s/slency/area/ugelan/road8.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�̬O�@���H��ө����c����D�A�A�ݨ쨭�Ǧ��@�Ӥj�۵P�A�W��
�g�ۡi�վB���Ȧ�j�A�ݨӬO�@���ѮȦ�̴����Φs�ڪ��Ȧ�A�o����
�D�W�����֪��y���ʪ��A�A�ݤF���T���Ǥ߯k�A�P���ߨϧA���ԦA�ݨ�
�o�ǥi�����ʪ��C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road9",
  "north" : __DIR__"bank",
  "east" : __DIR__"road1",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

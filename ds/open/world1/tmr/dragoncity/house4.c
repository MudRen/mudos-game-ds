// Room: /open/world1/tmr/dragoncity/house4.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Ы���");
	set("long", @LONG
�o�̬O�֫ө�������A�餺���s�L�ߡA����صۤ@�ǫC�ˡA�F��O
�X�ʪK���Z�����쵧���C�A�@���i�ӡA�N�D��@�}�}�M�s���B�H�H����
���A�ɬO�����⪺�{�������Ŧ⪺������A����A�T�A�����Ӧ��C
LONG
	);
	set("east", "house4e");
	set("no_clean_up", 0);
	set("west", "house4w");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"house4w",
  "south" : __DIR__"house3",
  "north" : __DIR__"house4n",
  "east" : __DIR__"house4e",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}

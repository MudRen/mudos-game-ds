// Room: /u/s/slency/area/ugelan/farm3.c

inherit ROOM;

void create()
{
	set("short", "�վB�����~������");
	set("long", "�o�̬O�վB�����~������������A�A�o�{�o�̪��g�[���G�ӹL����\n"", �]�]���èS���h�ֲ��A�b���ѺءA�o�̤��ީ�����ݳ��O�@���j����\n""�A�S������C���ΰ��s���̻١A���p��L�ڸs�q���B�i�i�J�վB�����A\n""�u�ȱN�O�@���E�T�C\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"farm6",
  "east" : __DIR__"farm1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "�p�ܮw");
	set("long", @LONG
�o�̬O�]���F�誺�a��C�o�ǪF��ܥi�঳���Ѫ�����~�B��
�դ������~�����A�ҥH�o�ǪF�観�ɭԷ|�o���N�Q���쪺�ĪG�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"out" : __DIR__"workroom",
	]));
	set("objects",([
		__DIR__"pill.c":1,
		__DIR__"lion.c":1,
	]));
	setup();
	replace_program(ROOM);
}

// Room: /open/world1/whoami/birdarea/en76.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�F�_[0m�A�L");
	set("long", @LONG
�A���_���F�L�ӡA���񪺾���٬O�@�˪��Z�K�A���O�A����
�����a���h�A�o�Q�s�s���k������¶�A�o���p�����F�詵���X
�h�A�i�H�ݨ�@�B�������ۥx�A���_�O����ߤ@������-�_�Z���A
�_�Z�����j�h�Ƨ����A���D�`�n�ȡA�A�i�H�Ҽ{�L�h���Ӹ}�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"en75",
  "north" : "/open/world1/tmr/north_bar/town1",
  "east" : __DIR__"en78",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}

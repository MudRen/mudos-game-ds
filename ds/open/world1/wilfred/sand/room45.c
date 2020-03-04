// Room: /open/world1/wilfred/sand/room45.c

inherit ROOM;

void create()
{
	set("short", "�Y�s��-�@���j���f");
	set("long", @LONG
�o�O�Y�s�����@���j���A�u���@�������ʨӤءA�e���Q�ت��j��
���F�@���e�P�����f�����C�Y�s�����x�ƾԲ��n�I�A���_���j�z��
��A�~��ۥb�H�b�ꪺ���ڡA�ͩʦn�ԡA�ƤQ�~�Ӥ@���Q�n���n�I��
�A�n�b���ѤU�Ĥ@�l�Ȥ֫ӭx�ڦu�Y�s���A�~�O�٥��ѤU�����w�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room44",
  "north" : "/open/world1/tmr/dragoncity/bridge1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

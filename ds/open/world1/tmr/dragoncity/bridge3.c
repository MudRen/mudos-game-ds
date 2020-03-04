// Room: /open/world1/tmr/dragoncity/bridge3.c

inherit ROOM;

void create()
{
	set("short", "�Y�s��-�����@���j��");
	set("long", @LONG
�A�����۽Y�s���n�����f�~���@���j���A�o��ƺ��F�Ʊ��������H�s
�򨮶��A���O���ۭn�i�����������A�ѩ�֫ӭx���ި�A�j�a���D�`
�u���ǵ��J����C���ɦ��p�ĨӦ^�b���A�@�����x�M�������H�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge2",
  "north" : __DIR__"southgate2",
]));
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

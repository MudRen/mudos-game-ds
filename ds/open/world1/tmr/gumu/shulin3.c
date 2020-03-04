// Room: /open/world1/tmr/gumu/shulin3.c

inherit ROOM;

void create()
{
	set("short", "�p��L");
	set("long", @LONG
�o���O��L����t�A�Ѥѥj��w�g�ܵ}�֤F�C�F�����@�y���s�A��
���ݨ��s������·¶���A���G�����\�Y�Ѫ��ص��C�s�սw�M�A���s�W��
�������a�⺡�F���C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"caodi",
  "west" : "/open/world1/moonhide/area/room1",
  "northeast" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}

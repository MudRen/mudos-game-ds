// Room: /open/world1/tmr/hasake/caoyuan2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C�_��M���䳣���n�h�b�O�A��
�F�i�H�ݨ��F�z����t�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"caoyuan1",
  "north" : __DIR__"caoyuan5",
  "south" : __DIR__"caoyuan9",
  "east" : __DIR__"caoyuan3",
]));

	setup();
	replace_program(ROOM);
}

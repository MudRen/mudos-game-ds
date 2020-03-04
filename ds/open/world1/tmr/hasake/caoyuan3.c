// Room: /open/world1/tmr/hasake/caoyuan3.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C����i�H�ݨ����ħJ�b�O�A��
�F�h�N�O�F�z�F�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caoyuan2",
  "north" : __DIR__"caoyuan4",
  "south" : __DIR__"caoyuan7",
]));

	setup();
	replace_program(ROOM);
}

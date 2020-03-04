// Room: /open/world1/tmr/dragoncity/north_din.c

inherit ROOM;

void create()
{
	set("short", "�B�r��");
	set("long", @LONG
�o�̬O�Y�s���_�����B�r��f�C�V�_�@���q�V�ȪZ���A
�F���M�譱�O�@���������C�ۤj��A�q�V�����C�n���O�@��
�W�\����[���˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"northroad2",
  "east" : __DIR__"northroad1",
  "north" : __DIR__"north1",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

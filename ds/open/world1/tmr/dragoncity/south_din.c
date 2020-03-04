// Room: /open/world1/tmr/dragoncity/south_din.c

inherit ROOM;

void create()
{
	set("short", "�B�r��");
	set("long", @LONG
�o�̬O�Y�s���n�����B�r��f�C�V�n�@���q�V�������A
�F���M�譱�O�@���������C�ۤj��A�q�V�����C�_���O�@��
�W�\����[���˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"southroad2",
  "south" : __DIR__"southgate1",
  "north" : __DIR__"house1",
  "east" : __DIR__"southroad1",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

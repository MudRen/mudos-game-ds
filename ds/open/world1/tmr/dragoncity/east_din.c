// Room: /open/world1/dragoncity/east_din.c

inherit ROOM;

void create()
{
	set("short", "�B�r��");
	set("long", @LONG
�o�̬O�Y�s���F�����B�r��f�C�V�F�@���q�V�C�s���A
�_���M�n���O�@���������C�ۤj��A�q�V�����C�譱�O�@��
�W�\����[���˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eastgate1",
  "south" : __DIR__"eastroad2",
  "north" : __DIR__"eastroad",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}

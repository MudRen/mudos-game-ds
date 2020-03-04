// Room: /open/world1/tmr/xiangyang/eastjie1.c

inherit ROOM;

void create()
{
	set("short", "�F�j��");
	set("long", @LONG
�o�O�@���e�諸�C�۪O��D�A�V�F����Y�����C�F��O�@
�Ӥj�Q�r��f�C�譱�O�����������s���A�_��O�����u���j�N
��������j���A�u������u�ƴ��Y�A�~���H���@��O���౵
�񪺡C�n���ƨӤ@�\�\���ĭ��A���A��ӬO�@�a�ľQ�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie1_w1",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"eastjie2_w1",
  "north" : __DIR__"jiangjungate",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -490,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}

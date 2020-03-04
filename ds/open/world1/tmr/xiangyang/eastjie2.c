// Room: /open/world1/tmr/xiangyang/eastjie2.c

inherit ROOM;

void create()
{
	set("short", "�F�j��");
	set("long", @LONG
�o��O�ܤj���Q�r��f�A�_��O�F���j��A�n���O�@����
�D�Ať�������H�@�볣��b�̭��A�F���q�V���������C�s���A
�V��i��F�����s���C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie2_w1.c",
  "south" : __DIR__"jiedao",
  "east" : __DIR__"eastjie2_e1.c",
  "north" : __DIR__"eastroad1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -480,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}

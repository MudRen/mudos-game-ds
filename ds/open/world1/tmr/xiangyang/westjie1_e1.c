// Room: /open/world1/tmr/xiangyang/westjie1_e1.c

inherit ROOM;

void create()
{
	set("short", "��j��");
	set("long", @LONG
�o�O�@���e�諸�C�۪O��D�A�V�F����Y�����C��W���H
��D�`�����A�ݪ��X�ӳo�@�a�D�`�����x�c�ءA�|�g�ɬO�@��
�ԩM����^�A�ʩm�̳��w�~�ַ~�C.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"westjie1",
  "east" : __DIR__"westjie1_e2",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -520,
  "z" : 0,
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}

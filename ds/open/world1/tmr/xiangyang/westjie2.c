// Room: /open/world1/tmr/xiangyang/westjie2.c

inherit ROOM;

void create()
{
	set("short", "��j��");
	set("long", @LONG
�o��O�ܤj���Q�r��f�A�_��O�褺�j��A�n���O�@�y�m
�ӡA�ӫe���������ۤ@��j�СA�W���Υ����g�ۡ��E�q�]���A
���ڡ����l�h���C�F��q�V�����s���A�譱�i�F�ժ���C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wusantong" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie2_w1.c",
  "south" : __DIR__"juyiyuan",
  "east" : __DIR__"westjie1",
  "north" : __DIR__"westroad1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -530,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�b�o�̬O�����s�U���s�}�ǡA�b�o�̦��X��H�a�A�]���@���p�p��
�Ӫ��p�e�y�y�L�A�b�e���٦��@�ǰ��k�b�~���窫�A���۪F��ԾĬ~��
�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin6.c",
  "east" : __DIR__"psin4.c",
    "west" : "/open/world1/moonhide/area/hotel",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

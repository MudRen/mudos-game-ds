// Room: /u/t/tmr/area/wynd.c

inherit ROOM;

void create()
{
	set("short", "�p�Ѥl");
	set("long", @LONG
�A�����b�@�����ᳱ�t���p�Ѥl�A�b���ѥդ餧�U�A���ѫo�]���
���ЫΦӪ��פF�j�����������Ӯg�A�����X�Ѥl�̪��@���I��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wynd2",
  "east" : __DIR__"street5.c",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/s/slency/area/ugelan/road15.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�̬O�@���C�۾Q�]�Ӧ�����D�A���W��H�����c���A�M��L��D
�èS���h�j�t�O�A�Ѧ�����O�վB���j�D�A���F�O�q�����F���Ϫ��@��
���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road16",
  "west" : __DIR__"road4",
  "east" : __DIR__"church1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

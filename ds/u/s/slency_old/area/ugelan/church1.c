// Room: /u/s/slency/area/ugelan/church1.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�̬O�@���ѫC�۾Q�]�Ӧ�����D�A���Ǻغ��F�U�ة_�Ყ��A��
���i�J�F�@�ӥͺA���A�P�ɸ��W�]�]�m�F���֮y�ȡA�Ѹ��H�𮧤���
�A���_�O�@���q���@���e�`���p�|�A����q���������ߡA���F�h�O�@�y
���j���Ϊ��s���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"church5",
  "west" : __DIR__"road15",
  "east" : __DIR__"church2",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

// Room: /u/s/slency/area/ugelan/church8.c

inherit ROOM;

void create()
{
	set("short", "�˪L�~��");
	set("long", @LONG
�o�̬O�վB�����F�_���᪺�@�y�˪L���~�򳡥��A���`���F�¤ҭ�
�i�J�˪L���¥~�A�èS������H�|�L�G�i�J���˪L�A�ѩ�o�y�˪L�L��
�e�j�A�]���]�S���H�M�����D�˪L��観����F��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"church7",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}

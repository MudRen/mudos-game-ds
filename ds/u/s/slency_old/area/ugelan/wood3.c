// Room: /u/s/slency/area/ugelan/wood3.c

inherit ROOM;

void create()
{
	set("short", "�˪L�t�B");
	set("long", @LONG
�A�U���̭����A���U�O���j�@�K�A�A���ɥi�H�ݨ�@�ǰʪ�����
�����e�A���i�_�{���O�o�̤@�w���@�Ǭr�V�r�~���ݡA�u���L�b�o���R
���`���˪L�̡A��b�����۫H�|�X�{����r�~�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wood4",
  "north" : __DIR__"wood2",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
       	setup();
	replace_program(ROOM);
}

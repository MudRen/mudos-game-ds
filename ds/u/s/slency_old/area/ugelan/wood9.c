// Room: /u/s/slency/area/ugelan/wood9.c

inherit ROOM;

void create()
{
	set("short", "�v�X���`");
	set("long", @LONG
�A�Ө�v�X�򪺴�`�A�o�̪��~�L���A�]���򭱴X�G�S������i��
�A�u���@�Ǥp�p�������A��ǳ�¶�۰��s�A�s���˼v�M���a�e�{�b����
�W�A���B�s�P���v�����A�ꤣ�i���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wood10",
  "south" : __DIR__"wood8",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}

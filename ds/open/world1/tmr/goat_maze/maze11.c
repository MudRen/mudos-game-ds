// Room: /open/world1/tmr/goat_maze/maze11.c

inherit ROOM;

void create()
{
	set("short", "�Ϩk���g�c - �����");
	set("long", @LONG
�A�����b�@�ӥH���Y��򦨪��g�c�A���G�O�X�d�~�e�N�ئb�o�˪L��
���C��⪺�C�a�Ϊ�󪦺��F�|�g�@���S�@��������A�P�˪L�۵M�ӵM�a
�ĦX�b�@�_�C�A���M���B�b�g�c�����A���O�ˤ]����۷Q�n���}�C
LONG
	);
	set("shrot", "�Ϩk���g�c - �����");
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bariour4" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"maze10",
  "north" : __DIR__"maze15",
  "west" : __DIR__"maze13",
  "east" : __DIR__"maze14",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

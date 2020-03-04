// Room: /open/world1/tmr/goat_maze/maze4.c

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
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"maze8",
  "southwest" : __DIR__"maze9",
  "west" : __DIR__"maze12",
  "east" : __DIR__"maze2",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

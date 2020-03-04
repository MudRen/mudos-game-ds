// Room: /open/world1/tmr/goat_maze/maze14.c

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
   __DIR__"npc/bariour4" : 4,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maze11",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

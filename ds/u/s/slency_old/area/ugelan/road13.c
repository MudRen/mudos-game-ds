// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "[1;33m�վB���j�D[2;37;0m");
	set("long",@LONG
�o�̬O�@����e�����F�誺����j�D�A���a���c�a�ꤣ�b�ܤU�A��
�Q��o���Ъٳ]�p�P���ذ������ө�����A�B�B�I���F�վB���Ұꤣ��
��~���ƹ�A���Ǧ��@�ǨѸ��H���}���y�ȡA���b����j�j�M���Q�ӬO
�O�H�o�K���ɨ��C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road12",
  "east" : __DIR__"road5",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

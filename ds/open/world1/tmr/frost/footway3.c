// Room: /open/world1/tmr/frost/footway3.c

inherit ROOM;

void create()
{
	set("short", "�̹D�f");
	set("long", @LONG
�A�����b�@���̹D�f�W�A�o���̹D�ة��y�۾F���p�y�����A��q��
���p�Ӧ�F�ʾ]�s�A�����a�P�i��B�D���G�Ӫ��������q���L�C���B�צ~
�M�x�A�������_�A���٬��w�~���n�a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"footway2",
  "east" : __DIR__"hill1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}

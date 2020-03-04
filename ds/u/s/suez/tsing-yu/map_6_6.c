// Room: /u/s/suez/tsing-yu/map_6_6.c

inherit ROOM;

void create()
{
	set("short", "�s���_");
	set("long", @LONG
    �ѧA�I��j�ӱj�P���g���A��Ǫ��X�H���r����]�Q���j�������̰�
�A�o�D���N�A���䪺�@���j�V�A���e�s�j���Ŧa�A�X�Ӧ�H�C���Y�֨B��
�L�A���ǡA��L�̪��H�v�����b��L���ѹD���A�A���@�سQ��󪺷Pı�C
�^�Q�l�D�~�p�֦p�e���s���M���e�����컷�誺�۪O�a�A�@�رj�P�����
�A�Aı�o�ۤv�����߳Q����F�襴�F�@�U�C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_7_5",
  "east" : __DIR__"map_6_7",
  "north" : __DIR__"map_5_6",
  "west" : __DIR__"map_6_5",
  "southeast" : __DIR__"map_7_7",
  "south" : __DIR__"map_7_6",
]));

	setup();
	replace_program(ROOM);
}

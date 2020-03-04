// Room: /u/s/superbug/train/8.c

inherit ROOM;

void create()
{
	set("short", "�a�U�K�J�f");
	set("long", @LONG
�o�̬O�q���a�U�K���J�f�A�ӱ�W�����۩U���M�Y���������A�ݰ_��
�w�g���@�}�l�S�H�ӥ����F�A�b�����٦��X�Ӭy���~���ݵۧA�A�A�y��ı
�o�ۤv�P�o�̮�椣�J�A�Q�n���I�k�}�C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"a-9.c",
  "south" : __DIR__"a-13.c",
  "north" : __DIR__"a-1.c",
  "east" : __DIR__"a-5.c",
  "climbdown" : __DIR__"1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

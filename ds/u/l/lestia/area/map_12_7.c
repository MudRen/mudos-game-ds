// Room: /u/l/lestia/area/map_12_7.c

inherit ROOM;

void create()
{
	set("short", "�]�O�̻�");
	set("long", @LONG

�o�̰g���ۤ@�ѥR���զ⪺����A�q�A���|�P�w�w�ɰ_���b���B�ӥh�A
���𤤳z�S�X�����H��A�·t���N�������A���T�����o�ݡA�A��۫e
��@����M�A��A�^�L���ɡA�A�o�{�A�w�g�`�`�����b�o���˪L�����F�C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"map_12_6",
  "east" : __DIR__"sn5",
  "north" : __DIR__"map_11_7",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}

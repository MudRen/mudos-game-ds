// Room: /u/l/lestia/area/map_2_4.c

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
	set("no_clean_up", 0);
	set("world", "undefine");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_2_5",
  "west" : __DIR__"map_2_3",
]));

	setup();
	replace_program(ROOM);
}

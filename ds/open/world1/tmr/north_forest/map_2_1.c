// Room: /u/l/lestia/area/map_2_1.c

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
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_2_2",
  "south" : __DIR__"map_3_1",
]));

	setup();
	replace_program(ROOM);
}

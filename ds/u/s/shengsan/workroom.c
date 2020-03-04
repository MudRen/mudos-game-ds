// Room: /u/s/shengsan/workroom.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36m���Ū��ѥ�ͮx�|[0m");
	set("long", @LONG
�o�̬O���Ū��ѥ�ͮx�|�A�S���Ӧh���Z�c�A�]�S���Ӧh��
�H�����ơC�@���L�~�P�L�{���i�H�b�o���R���x�|�����A���
���y���n�A�S�S�������n�Ať�o���A���q���ɡA�{�p�ۤv�w�g��
�F�H�����b�g���餧���F�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/beauty" : 1,
		"/u/s/shengsan/npc/handsome" : 1,
	]));


	set("exits", ([ /* sizeof() == 7 */
		"wiz": "/d/wiz/hall1",
		"west" : SHENGSAN1+"testarea/landroom",
		"play":	SHENGSAN2"game/playroom",
		"east": __DIR__"mine/room01",
		"marry": SHENGSAN2+"marryhome/househ1"
            ]));

	set("light", 1);
	set("valid_startroom",1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/shengsan_b.c", "???");
	replace_program(ROOM);
}

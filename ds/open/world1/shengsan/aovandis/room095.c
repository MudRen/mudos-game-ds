// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���v�u�|"NOR);
	set("long", @LONG
�o�̦��ܦh�����v�`�`�b�o���|�C���ܦh���]�k�Ĥ��M�]���b���䪺
��W�M����A�����u�ӫG�F��өж��A���H���ح��P���ɪ��Pı�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room101",
	    "west" : __DIR__"room090",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}
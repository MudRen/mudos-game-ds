// Room: /u/b/bennyng/area/room5.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ЬӤj�U�e��");
	set("long", @LONG
�A���e�@�I�N�O�Q�G�c���̫�@�c�F�A�A�P��F�̫᪺�ĤH�N�b�e��
���j�����C��A�^�Q�_���e���M�ԡA�ש󨣨�̲ת��ĤH�СбЬӡA�O�A
���ۥD�a�S�X�ӧQ���L���C
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room6",
  "north" : __DIR__"room4",
]));
        create_door("north","�j������","south",DOOR_CLOSED);
        set("objects", ([
  __DIR__"npc/guard.c":2,
]));
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

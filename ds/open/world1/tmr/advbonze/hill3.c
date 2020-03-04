#include <path.h>

inherit ROOM;

void create()
{
        set("short", "�ⶳ�p�Фs���Y");
        set("long", @LONG
�A�����b�@���ᬰ�T���������s���A�D����Ǫ����F�A��A�L��
�@���ԩM���R����^�A�A�i���ɬݨ�@�ǩM�|�L���C���n����V�O�X
�s���D���A���n�h�O��`�J�s���Y�C
LONG
        );
        set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "north" : __DIR__"hill4.c",
                "south" : __DIR__"hill2.c",
        ]));
        set("outdoors","forest");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("���к��H��",({"board"}));
set("location","/u/f/fanny/workroom.c");
        set("board_id", "fanny_b");
        set("long",
        "�@���K�K�³¼g���F�r������O�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

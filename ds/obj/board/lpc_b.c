#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"LPC �Q�ת�" NOR, ({ "lpc board","board", "lpc" }));
        set("location", "/u/c/cominging/bookroom.c");
        set("board_id", "lpc");
        set("long","�o�O�@�ӥΨӰQ�� LPC �������I\n");
        setup();
        set("capacity", 100);
        set("master",({ "cominging" }));
}


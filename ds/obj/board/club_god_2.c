#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("神族幹譙版", ({"god damn board", "board"}));
        set("location","/open/world1/god_club/eldership.c");
        set("board_id", "club_god_2");
        set("long", @long

幹譙專用，不夠賤，不夠狠，不夠毒，不准上版。
神諭的使用方法請見 help board。

long);
        set("master", ({ CLUB_D->query_club_leader("god") }));
        setup();
        set("capacity", 99);
}

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("神諭", ({"god's board", "board"}));
        set("location","/open/world1/god_club/boardroom.c");
        set("board_id", "club_god_1");
        set("long", @long

當眾神們有事情要商量或要公佈一些事情時，都會貼於此板上。
神諭的使用方法請見 help board。

long);
        set("master", ({ CLUB_D->query_club_leader("god") }));
        setup();
        set("capacity", 99);
}


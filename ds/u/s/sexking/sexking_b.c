#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("小麥草打屁留言板",({"board"}));
        set("location","/u/s/sexking/workroom/sexking_room2.c");
        set("board_id", "sexking_b");
        set("long","這是用天然麥草做的可愛留言板,你不禁想灌灌水,湊湊熱鬧。\n"
);
        setup();
        set("capacity",100);
}   

#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("神武教留言板",({"board"}));
        set("location","/u/a/acme/workroom.c");
        set("board_id", "acme_b");
   set("master",({"acme"}) );
        set("long",
        "這是一塊神武教專用的留言板。\n");
        setup();
        set("capacity",100);

}

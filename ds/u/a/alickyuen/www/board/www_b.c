#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIY"����p�i�R"NOR, ({ "board" }) );
    set("location", "/u/w/www/workroom");
    set("board_id", "www_b");
    set("long","�d�N��C\n" );
    setup();
    set("capacity",100);
    set("master",({ "www" }));
}

string query_save_file()
{
    return __DIR__+this_object()->query("board_id");  
}


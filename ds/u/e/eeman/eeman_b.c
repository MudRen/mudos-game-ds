#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIR"黑板"NOR, ({ "blackboard" }) );
        set("location", "/u/e/eeman/workroom");
        set("board_id", "eeman_b");
        set("long",     "普通的黑板, 用來記東西的\n" );
        setup();
        set("capacity", 100);
        set("master",({ "eeman" }) );
}
string query_save_file()
{
return "/u/e/eeman/"+query("board_id");
}

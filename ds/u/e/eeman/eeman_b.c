#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIR"�ªO"NOR, ({ "blackboard" }) );
        set("location", "/u/e/eeman/workroom");
        set("board_id", "eeman_b");
        set("long",     "���q���ªO, �ΨӰO�F�誺\n" );
        setup();
        set("capacity", 100);
        set("master",({ "eeman" }) );
}
string query_save_file()
{
return "/u/e/eeman/"+query("board_id");
}

#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"現代小語"NOR, ({ "now board","board" }) );
        set("location", "/d/wiz/now");
        set("board_id", "now_b");
        set("long",     "用來記東西的\n" );
        setup();
        set("capacity", 100);
        set("master",({ "eeman" }) );
}
string query_save_file()
{
return "/d/wiz/"+query("board_id");
}

#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"�{�N�p�y"NOR, ({ "now board","board" }) );
set("location","/open/world2/meetroom");
        set("board_id", "now_b");
        set("long",     "�ΨӰO�F�誺\n" );
        setup();
        set("capacity", 100);
        set("master",({ "eeman" }) );
}
string query_save_file()
{
return "/u/e/eeman/"+query("board_id");
}

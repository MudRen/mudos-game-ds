#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(CYN"�C��"NOR, ({ "sword board","board" }));
        set("location", "/open/world1/meetroom"); 
        set("board_id", "linjack_b");
        set("long","�o�O�Q�����j���s��, �W�������ѼC��覨����r..\n" );
        setup();
        set("capacity", 100);
        set("master",({ "linjack" }));
}
string query_save_file()
{
return "/u/l/linjack/"+query("board_id");
}

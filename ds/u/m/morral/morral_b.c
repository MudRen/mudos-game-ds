#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"�ɪŰO�ƪO"NOR, ({ "board" }) );
        set("location", "/open/world3/meetroom");
        set("board_id", "morral_b");
        set("long",     "�o�O���t�d���Ӫ��Ův�O�ƥΪ��C \n" );
        setup();
        set("capacity", 100);
        set("master",({ "morral" }) );
}
string query_save_file()
{
return "/u/m/morral/"+query("board_id");
}

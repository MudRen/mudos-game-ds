#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIG"天城告示欄"NOR,({"sky city board","board"}));
        set("location","/open/world1/acme/area/hotel");
           set("board_id","acme_h1_b");
        set("long",
        "這是由天城官府所在此所設置的告示欄，官府若有重大事件會在此處公佈。\n");
        setup();
        set("capacity",100);
}

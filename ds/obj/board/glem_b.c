#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIG"錢的布告欄"NOR,({"Glem's board","board"}));
set("location","/u/g/glem/workroom");
set("board_id","glem_b");
        set("long",
"這是Glem 的布告欄。\n");
        setup();
        set("capacity",100);
set("master","glem");   
}

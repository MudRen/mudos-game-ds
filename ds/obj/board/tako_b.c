#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIY"布丁"HIW"盒"NOR,({"poo ding board","board"}));
          set("location","/u/t/tako/workroom.c");
        set("board_id", "tako_b");
        set("long",
        "用布丁盒造型的留言板，任何人有事都能在上面留言的。\n");
        setup();
        set("capacity",50);  
replace_program(BULLETIN_BOARD);
 
}






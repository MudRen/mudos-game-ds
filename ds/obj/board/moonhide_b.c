#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"Moonhide's Board"NOR,({"board"}));
          set("location","/u/m/moonhide/workroom");
        set("board_id", "moonhide_workroom_b");
        set("long",
        "[0;5;34m�[5m�[5m�[5md[5m�[5m�[0m�C\n");
        setup();
        set("capacity",100);
  set("master",({ "moonhide"}));
 
}


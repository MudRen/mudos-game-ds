#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"朝天留言版"NOR,({"board"}));
          set("location","/open/world1/tmr/area/hotel");
        set("board_id", "tmr_hotel_b");
        set("long",
        "一張木製的留言板，任何人有事都能在上面留言的。\n");
        setup();
          set("capacity",1000);
  set("master",({ "tmr","acme","cominging","luky", "alickyuen"}));
 
}


#include <ansi.h>
inherit ROOM;
void create()
{
      set("short", HIR"令伊小房間"NOR);
      set("long", HIW"\n\t令伊的房間...什麼都沒有。\n\n"
                     "\n\t四處都很簡陋...請多包涵\n\n"                                                
      NOR);
             
    set("no_clean_up",0);        
    set("light",1);               
    set("exits", ([
    "start"  : "/open/world2/anfernee/start/hall", 
    "wiz" : "/d/wiz/hall1",
    "tra" : "/open/world1/tmr/area/hotel",
      "east" : __DIR__"test",
    ]));
        set("light",1);
        set("valid_startroom", 1);
    setup();
//	call_other("/obj/board/orzer_b", "???" ); by alick
    replace_program(ROOM);
}



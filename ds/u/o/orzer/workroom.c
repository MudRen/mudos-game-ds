#include <ansi.h>
inherit ROOM;
void create()
{
      set("short", HIR"�O��p�ж�"NOR);
      set("long", HIW"\n\t�O�쪺�ж�...���򳣨S���C\n\n"
                     "\n\t�|�B����²��...�Цh�]�[\n\n"                                                
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



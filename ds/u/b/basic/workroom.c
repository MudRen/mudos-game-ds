#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
 set("short", HIY"逍遙"HIM"夢境"NOR);

 set("long",
            HIY"\n\t逍遙，是不用別人去管才叫逍遙。\n"
            HIC  "\t自在，是不受外界的約束才叫自在。\n"
            HIM  "\t夢，是用長長的織線編織起來的。 \n"
            HIW  "\t幻境，是結合大自然的一切跟本...\n\n"NOR
            );
       set("objects",([
          "/u/b/basic/item/box" :1,

]));
      set("exits", ([ /* sizeof() == 7*/
            "down" :"/u/a/acme/workroom",
            "luky" :"/u/l/luky/workroom",
            "tmr"  :"/u/t/tmr/workroom" ,
            "cominging":"/u/c/cominging/workroom",
            "wizard" :"/d/wiz/hall1",
            "kelly" :"/u/c/cutekelly/workroom",
            "sex" :"/u/s/sexking/workroom",

]));
set("light",1);
      set("valid_startroom", 1);
         setup();
call_other("/obj/board/basic_b", "???");
}

#include <room.h> 
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG 
你看到這兒的植物比剛才更茂密, 而且還多了幾株灌木, 這
裡的空氣非常的清新, 令你不想離開, 想多待幾下, 不過聽說這
裡危機重重, 還是趕快走吧.
LONG
    );
 
 set("exits",(["northwest":__DIR__"en41",
               "southeast":__DIR__"en39",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"西廂房"NOR);
        set("long", @LONG
你進去走廊的西邊那房間，擺設整齊，房裡內的東西都很普通，
想必這些應該只是普通外地來的訪客所休憩、習書的地方吧。
LONG
 );       
        
  set("exits", ([ /* sizeof() == 1 */
  "east"  : __DIR__"room15",
  
]));  
        set("no_clean_up", 0);
        setup();
}     


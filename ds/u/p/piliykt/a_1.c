#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIG"豪華走道"NOR);
set("long", @LONG
這是一條超長的豪華走道, 這裡的地板都用黃金舖造而成, 這條走道
兩旁還有許多的古董, 讓你看的愛不釋手.
LONG
);
set("light",1);
set("exits", ([ 

                "north"  : __DIR__"workroom.c",
                "south"  : __DIR__"workroom_2.c",
                                                
                           ]));
 setup();
}


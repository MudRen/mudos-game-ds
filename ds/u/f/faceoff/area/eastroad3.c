#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"隱士樓"NOR);

 set("long",@LONG
這裡就是著名武林的隱士樓了, 這裡住的都是一些看破世間
的隱居高士, 由於天梟的過往盛名因此倒也沒有其他武林中人會
來這裡騷擾, 而尉遲妄也不過問這裡的事, 所以此處實是隱居的
天堂.
LONG
    );
 set("exits",([ "east":__DIR__"woodhouse1",
                "west":__DIR__"eastroad2",
                "south":__DIR__"woodhouse2",
                "north":__DIR__"eastroad4",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

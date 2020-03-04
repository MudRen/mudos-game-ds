#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
『答•答•答•答』，規率的聲音，來自洞頂的水滴，每次的
聲響，傳遍每個地方，幽暗的東方，與西方的光亮，形成強烈的對
比。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room19",  
  "south" : __DIR__"room17",
  "east" : __DIR__"room13",
  "north" : __DIR__"room15",]));
        set("no_clean_up", 0);

        setup();
}


#include <path.h>
inherit ROOM;
void create()
{
        set("short", "森林間");
        set("long",@LONG
這裡是森林之中的一條小路，在這裡之間有許許多多的野生動植物，
也有些的顏色非常的鮮艷，看來是種含劇毒的東西，東北邊有一塊空地
，陽光很充足的樣子。
LONG
        );
        set("exits", ([
  "southwest" : TMR_PAST+"area/city-door.c",
  "northeast" : __DIR__"forest4.c", 
  ]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


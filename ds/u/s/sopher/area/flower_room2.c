#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIG"迷你森林"NOR);
        set ("long", @LONG

                  ▲    ▲    ▲    ▲    ▲    ▲    ▲
  【迷你森林】    ∥ ▲ ∥ ▲ ∥ ▲ ∥ ▲ ∥ ▲ ∥ ▲ ∥
                  ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥ ∥
你來到一間小小的密室，歌聲正由此處傳來，擬向
四周望了望：一大片綠油油的植物，簡直就像置身於森
林般的快活，你貪婪的吸著芬多精享受大自然的樂趣，
你前面突然出現了一個人影....是一位....女生???
LONG);   
        set("light",1);
        set("exits", ([
        "south": __DIR__"flower_room",
         ]) );
        set("objects", ([
        __DIR__"npc/sfuna" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}


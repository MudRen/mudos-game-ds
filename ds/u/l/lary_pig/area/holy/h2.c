#include "path.h"
inherit ROOM;

void create()
{
        set("short", "殘破的石階");
        set("long", @LONG
強烈的好奇心戰勝一切，你努力的克服心中的恐懼，不顧一切爬上
這不知通往何處的階梯。在你腳邊，不時傳來碎石掉落的聲音，看來,
長年的風化，也使的如此堅硬的石階殘破不堪...
LONG
        );

        set("exits", ([
  "east" : HOLY+"h1",
 "westup" : HOLY+"h3",
        ]) );
        set("light",1);
        setup();
}

#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
美麗的星空、充滿悽涼古意的石階，在這兩種美景的相互交會下
，更使整個聖域籠罩在一片神秘之中•只剩兩宮了，你心裡如此的想
著，想到再通過兩宮就可以揭開聖域的神秘面裟，你不由的心跳加速
、加快腳步前進。
LONG
        );

        set("exits", ([
  "east" : HOLY+"h23",
 "westup" : HOLY+"h21",
        ]) );
        set("light",1);
        setup();
}

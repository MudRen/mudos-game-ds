#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
費盡千辛萬苦，總算擊退雙子宮守護者，你深深的體會到人性
的可怕及可悲，雙子宮守護者的『修。羅。煉。獄』，也讓你對人
生有了新的體驗，你感到，這一路上的辛苦種算沒有白費，想到這
裡，你不由得加快腳步，向巨蟹宮邁進。
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h7",
 "westdown" : HOLY+"h9",
        ]) );
        set("light",1);
        setup();
}

#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
經過不斷的努力, 你終於走完前六宮了, 雖然前方還有六個關卡
在等著你, 也不知將會遇到什麼樣的敵人, 但是, 你相信, 以你堅強
的意志力, 一定能突破重重考驗的！
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h15",
 "westdown" : HOLY+"h13",
        ]) );
        set("light",1);
        setup();
}

#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
在通過獅子宮後，和往常一樣，眼前依舊是一成不變的的石階，
在經過前面數宮的考驗後，你深刻的體會到，恆心及毅力的重要，仔
細想想，這些漫無邊際的階梯，不正是磨練一個人的耐力最佳方法嗎
？
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h11",
 "westup" : HOLY+"h13",
        ]) );
        set("light",1);
        setup();
}

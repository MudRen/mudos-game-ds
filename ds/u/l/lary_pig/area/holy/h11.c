#include "path.h"
inherit ROOM;

void create()
{
        set("short", "獅子宮");
        set("long", @LONG
一踏入獅子宮，你不由得倒抽一口涼氣，一頭巨大的獅子，居然
像頭小貓似的依靠在一高大男人的身邊撒嬌，看那男子一身結實無比
的肌肉，你不禁在心中盤算著，你和他對打的勝算。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h10",
 "westup" : HOLY+"h12",
        ]) );
        set("light",1);
        setup();
}

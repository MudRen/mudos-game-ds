#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
你好不容易的通過前面數宮，走過無數的石階，但是，盡管是強
壯如你，也不禁感到一陣頭暈目眩，漸入昏迷狀態，在你眼前，有許
多綠色的小精靈在跳啊跳著，好快樂啊！
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h19",
 "westdown" : HOLY+"h17",
        ]) );
        set("light",1);
        setup();
}

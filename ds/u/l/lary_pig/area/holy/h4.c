#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
好不容易的通過牡羊宮的試鍊，你正踏在前往金牛宮的路上，走
在這種殘破的石階上，盡管是身經百戰的你，也感到身體有些不適。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h3",
 "westup" : HOLY+"h5",
        ]) );
        set("light",1);
        setup();
}

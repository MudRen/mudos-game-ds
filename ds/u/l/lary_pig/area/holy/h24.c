#include "path.h"
inherit ROOM;

void create()
{
        set("short", "石階");
        set("long", @LONG
前方的不遠處，就是聖域 ─ 黃道十二宮的最後一座宮殿了，你
的心裡感到十分的興奮，也十分的緊張，畢竟，在前面幾宮，與守護
者的戰鬥，都逼的你喘不過氣來，你回頭望望之前走過的幾座宮殿，
一咬牙根，大步向前邁進！
LONG
        );

        set("exits", ([
  "east" : HOLY+"h25",
 "westdown" : HOLY+"h23",
        ]) );
        set("light",1);
        setup();
}

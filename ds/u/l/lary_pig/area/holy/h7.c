#include "path.h"
inherit ROOM;

void create()
{
        set("short", "雙子宮");
        set("long", @LONG
雙子宮，這是黃道十二宮之中，變化最多，最另人難以捉摸的星
座，根據遠古的傳說，雙子座的人，比一般人更能完全表現出人類至
善和極惡的一面，所以，來到這兒的人們啊，你們千萬要好自為之， 
否則，此宮的守護者，將會讓你見識到真正的『修。羅。煉。獄』
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h6",
 "westdown" : HOLY+"h8",
        ]) );
        set("light",1);
        setup();
}

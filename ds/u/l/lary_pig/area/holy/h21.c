#include "path.h"
inherit ROOM;

void create()
{
        set("short", "魔羯宮");
        set("long", @LONG
黃道十二宮的第十宮 ─ 魔羯宮，魔羯，是一種擁有山羊上半身
，魚的下半身的一種奇特的生物，在此宮的牆上，也刻畫著魔羯的畫
像呢。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h22",
 "west" : HOLY+"h20",
        ]) );
        set("light",1);
        setup();
}

#include "path.h"
inherit ROOM;

void create()
{
        set("short", "天秤宮");
        set("long", @LONG
黃道十二宮的第七宮 ─ 天秤宮，天秤，顧名思義，便是只測量
物品重量是否均衡的工具，而面對此宮的考驗亦是如此，只要你能使
此宮守護者所持有的真理之秤達到平衡，方可通過，否則，就戰吧！
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h16",
 "westdown" : HOLY+"h14",
        ]) );
        set("light",1);
        setup();
}

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"小木屋"NOR);
 set("long",@LONG
這裡是村民的家, 你四周看看, 這裡擺些村民的日用品, 你
聽到屋頂上有些許喘息聲, 他們對你的出現很驚訝並且不高興, 
你最好快點離開這.
LONG
    );
 
 set("exits",(["west":__DIR__"village15",
              ]));
 set("item_desc",([
        "屋頂":"你看了看屋頂，發覺沒什麼特別的..\n
               (你仔細一想，這裡是室內當然什麼都看不到)\n", 
    ]));
 
 set("objects",([__DIR__"npc/child" : 1,
                 __DIR__"npc/villager2" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

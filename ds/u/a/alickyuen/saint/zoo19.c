// Room: /u/a/alickyuen/area/zoo19.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Station＠CyberZoo"NOR);
	set("long", @LONG
這�堿O動物園的舉報處，沒有什麼特別，你只是看到一張桌子，若你
發現有什麼奇怪事情或有一些動物出走的話都可以來這裡通知這裡的管理
員。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoo6",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "桌子" : "一張用冰做成桌子，是用了未來的最新的科技來做的，所以那些冰不會溶\n"
"化。這張桌子晶瑩剔透，你彷彿看見什麼在閃著。\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}
void init()
{
add_action("do_search","search");
}
int do_search(string arg)
{
        object me, obj;
        me=this_player();
        if (arg != "桌子" || me->query_temp("quest/animal") ) 
                   return 0;
        else {
                   message_vision("$N敲敲翻翻，發現桌底有一個紅色的制。\n\n" ,me);
me->set_temp("quest/animal",1);
obj=new(__DIR__"npc/controller2");
obj->move(__DIR__"zoo19");
           return 1;
                 }
}

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"石洞內"NOR);
 set("long",@LONG 
這裡似乎有一雙凶惡的眼睛在瞪你，讓你感覺到十分恐懼。
眼看著外面的怪物跑進來，讓你進退也不是。到底該怎麼辦呢？
要出去就要全靠你自己啦！ 
LONG
    );

       set("exits",([      
       "south":__DIR__"s7",             ]));
        set("objects", ([
           __DIR__"npc/soul" :1,
           ]));
 set("no_clean_up", 0);
 setup();
}


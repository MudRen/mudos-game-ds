#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG
這裡的旁邊是市集，有許多攤販的叫賣聲以及喧嘩聲，市集 
裡有賣很多商品，也有藥房，如果你有需要的話，可以去看看唷
！這裡的東西都很便宜的！而右邊是一口井，可以去那裡飲水。

LONG
    );

       set("exits",([
       "north":__DIR__"town14",
       "south":__DIR__"town10",
       "east":__DIR__"town6",
       "west":__DIR__"town18",
           ]));

        set("objects", ([
           __DIR__"npc/villager" :2,
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     


#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIW+BLK"石穴"NOR);
set("long", @LONG 
你毫無防備的掉到這個石穴裡，這裡熱得讓人以為到了火山
裡頭。在石穴的深處發現了一個熔爐，冒出熊熊火燄。旁邊還有
一位獨臂老人正在打造一把劍，他對你的到來似乎很高興, 在這
裡也有一個石像, 可是好像跟你剛才所看到的不太一樣.....
LONG
        );
        set("objects",([__DIR__"npc/ooldman" : 1,
                        __DIR__"npc/statue2" : 1,
               ]));
        set("no_clean_up", 0); 
        set("light",1);        setup();
}
void init()
{
        add_action("do_roll","roll");
}
int do_roll(string arg)
{
        object me;
        me=this_player();
        if (arg != "石像的頭" && arg != "頭") return 0;
        else {
               message_vision("只見$N把"HIW+BLK"石像"NOR"的頭一轉，出現了一個通往上方的梯子。\n\n",me);
               set("exits",([
               "up" : __DIR__"en78",
               ]) );
           return 1;
        }
}          


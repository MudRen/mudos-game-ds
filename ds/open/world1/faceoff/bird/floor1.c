#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"柱頂"NOR);
 set("long",@LONG
你一躍上柱頂才發現, 原來柱頂還有一個神像, 可是在這裡
你得要彎著身子, 相當的不舒服, 令你想離開這裡!
LONG
    );
 set("exits",([ "down":__DIR__"pill13",
    ]));
 set("item_desc",([
        "神像":"你發現這是一隻梟的神像, 而且祂的脖頸有一條項鍊, 你可以把它拿(take)下來.\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();               
}
void init()
{
        add_action("do_take","take");
}
int k=1;
int do_take(string arg)
{
      object me,p;
      me=this_player();
      if (arg != "項鍊") return 0;
      message_vision("$N開始考慮要不要拿下項鍊\n"  ,me);
if(k != 0){
           message_vision(HIY"$N終究還是把項鍊拿了下來!\n"NOR ,me);
           k = 0;
        p=new(__DIR__"npc/eq/sky_neck.c");
        p->move(this_player());
        } else
        {
                message_vision("$N想了一想, 還是不要好了....\n",me);
        }                               
        return 1;
}
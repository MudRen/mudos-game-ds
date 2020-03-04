#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹幹");

 set("long",@LONG
你現在位於參天古木的樹枝上, 你望了一望四周, 竟然隱約
可見到十萬大山中的奇倪峰, 可見神木的高度真是空前絕後而且
你腳下的樹幹大約有十人環抱的寬度, 你再向後看了一看發現你
腳下有許多的爪印, 並且都通向你東邊的樹洞之中, 接著你又發
現地上有許多毛蟲的屍體, 看來毛蟲唯一的避難所只有那個樹洞
了.......
LONG
    );
 set("exits",([ "down":__DIR__"tree9",
                "west":__DIR__"tree_2F1",
    ]));
 set("no_clean_up", 0);
 set("objects", ([__DIR__"npc/crow" : 4+random(3),
    ]));

 setup();

}

void init()
{
        add_action("do_search","search");
       add_action("do_enter","enter");
}
int k=1;
int do_search(string arg)
{
        object me;
        object p;
        me=this_player();
 
       if (arg != "樹洞") return 0;
       message_vision("$N伸手在樹洞中摸了一摸.....\n"  ,me);
       if(k != 0){
           message_vision("$N從樹洞中摸出一隻小毛蟲！！\n" ,me);
           k = 0;
        p=new(__DIR__"obj/green_worm.c");
        p->move(this_player());
        } else {
        message_vision("$N摸了一摸，就算$N摸到海枯\石爛也摸不出個屁.....:P\n",me);
        }                               
        return 1;
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "樹洞") return 0;
        message_vision("$N似乎瘋了, 使盡了吃奶的力氣想要擠進一個只有他手掌大的樹洞......\n"  ,me);
}


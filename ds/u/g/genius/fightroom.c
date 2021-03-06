#include <room.h>
#include <ansi.h>
inherit ROOM;

int doorOpen=0;
int buttonAppear=0;

void create()
{
set("short",HIR"鮮血製造間"NOR);
set("long", @LONG
這裡有著亂七八糟的生物，有簡單的也有複雜的，讓人有殺戮的慾
望。這裡有一張血紅的告示(sign)。
LONG
);
set("no_recall",1);
set("light",0);
set("no_map",1);

set("item_desc", ([
"sign":"上面寫著:\n\n"HIR"!!!  殺  • 無 • 赦  !!!\n\n\n"NOR,
"wall":"一面濺滿血的牆。\n"NOR,
]));

set("exits", ([
"up": "/u/g/genius/roomenter.c",
      "cold": "/open/world1/tmr/bagi/ghat9.c",
      "dab": "/open/world1/tmr/area/wa8",
      "dra": "/open/world1/wilfred/sand/room90",
]));


      set("objects",([
      "/u/g/genius/area/npc/beetleguard" : 1,
      "/open/world1/acme/area/npc/woodman" : 3,
      ]));
      setup();
}

void init()
{
        add_action("do_touch","touch");
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me;
        int tempI;
        me=this_player();
        tempI=random(9);
        if( me->is_busy() ) {return 0;}
        if(!arg || arg!="wall") return 0;
        if(tempI<=3)
        {
        write("你仔細研究這面牆，發現一個機鈕(button)。可以按按看(touch)。\n");
        set("item_desc/button", "這是一個八角形的按鈕\n") ;
        buttonAppear=1;
        }
        else
        {
        message_vision("$N在牆壁上找了又找，什麼也沒發現\n",me);
        me->start_busy(2);
        }
        return 1 ;
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if( me->is_busy() ) {return 0;} 
        if(!arg || arg!="button" ||buttonAppear=0) return 0;
        message_vision("$N按下了按鈕。\n",me);
        if(!doorOpen)
        {
        message_vision("牆壁的中央忽然陷入地底，$N的面前出現了一個出口！\n",me);
        set ("exits/enter","/u/g/genius/area/firstroom",);
        doorOpen=1;
        }
        else
        {
        message_vision("牆壁的缺口升上一片石壁，將$N面前的出口堵住了。\n",me);
        delete ("exits/enter");
        doorOpen=0;
        }
        return 1;        
}


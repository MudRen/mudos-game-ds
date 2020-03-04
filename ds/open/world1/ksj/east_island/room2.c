#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
 set("short","沙灘");
 set("long",@LONG
這裡是一片小沙灘，沙灘上停著幾艘小船，偶而可以看到幾隻螃
蟹爬過，海浪隨著海風輕輕地拍打在沙灘上，不時地沖上來幾塊貝殼
，遠遠地就聽得到海鷗的叫聲。
LONG
    );
   set("exits",([ 
       "southwest":__DIR__"room4",
       "northeast":__DIR__"room1",
       "south":__DIR__"room3",
     ]));
   set("item_desc",([
       "貝殼" : "仔細搜尋說不定可以找到漂亮完整的貝殼\n",
     ]));
   set("objects",([
      __DIR__"npc/crab":2,
     ]));
   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me=this_player(),necklace;
        necklace = new(__DIR__"npc/eq/seashell-necklace.c");
        if(query_temp("necklace1")) return notify_fail("你找了一會兒，一無所獲。\n");
        if(arg !="貝殼" )
                return notify_fail("你要找什麼東西呀？\n");
        else {
                message_vision("$N東翻翻西翻翻，找到了一條扇貝頸飾。\n",me);
                necklace->move(me);
             } 
        set_temp("necklace1",1);
        call_out("delay",1200,this_object());
        return 1;
}

void delay(object room)
{
     delete_temp("necklace1");
}

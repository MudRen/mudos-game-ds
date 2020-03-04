#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","東北澤林");
set("long", @LONG
你來到泥沼區的深處, 四周一片死寂, 在你的正前
方有一塊大石, 在大石的四周長滿了雜草, 無法繼續前
進了....
LONG
        );
        set("exits",(["north":__DIR__"en69",
                      "northwest":__DIR__"en68",
               ]));
        
        set("item_desc",([
        "大石":"你仔細看了看這塊石頭, 發現石頭中央有一塊發光物體, 在大石上有一個手印,
似乎可以把手放進去(push)。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
int stone = 1;
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
          object ob;
          object me;
          me=this_player();
          if (arg != "大石") return 0;
          message_vision("$N突然心血來潮，用雙手灌滿了內勁。\n",me);
          message_vision("只見$N用力的把雙手往大石上搥了下去。\n",me);
          message_vision("只見大石中的發光部份被$N的內勁震了出來。\n",me);
          if(stone != 0){
                     message_vision(HIG"$N得到了一塊鐵石！！\n\n"NOR ,me);
                     stone = 0;

                     ob=new(__DIR__"npc/obj/iron2");
                     ob->move(this_player());
                         } 
         else{
                message_vision("但是因為$N的內勁控制不佳，那發光體不知飛向何處。\n",me);
             }                               
        return 1;
}



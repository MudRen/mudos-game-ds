#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
set("short",HIW"東北"NOR"澤林－"YEL"泥沼區"NOR"深處");
set("long", @LONG
你來到泥沼區的深處, 四周一片死寂, 在你的正前方有一塊
大石, 在大石的四周長滿了雜草, 無法繼續前進了....
LONG
        );
        set("exits",(["north":__DIR__"en69",
                      "northwest":__DIR__"en68",
               ]));
        
        set("item_desc",([
        "大石":"你仔細看了看這塊石頭, 發現石頭中央有一塊發光物體, 在大石上有一個手印,
你有一股衝動想要去推推看。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land"); 
        set("reborn",3600);        setup();
}
int stone = 1;
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
          object ob,ob1,ob2,ob3;
          object me;
          me=this_player(); 
        if (!arg || arg =="")
        return notify_fail("你要推什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
          if (arg != "大石") return 0;
          if(me->query_skill("force") >= 100 && me->query("ap") >=1200 )
          {
                message_vision("$N突然心血來潮，用雙手灌滿了內勁。\n",me); 
                message_vision("只見$N用力的把雙手往大石上搥了下去。\n",me);
          if(stone != 0){
                message_vision("只見大石中的發光部份被$N的內勁震了出來。\n",me);
                me->receive_damage("ap",1000);
                stone = 0;
                switch( random(10) ){
                default:
                ob1=new(__DIR__"npc/obj/iron");
                ob1->move(this_player());
                message_vision(HIG"$N得到了一塊"+ob1->query("name")+"！！\n\n"NOR ,me);
                break;
                case 1:
                ob=new(__DIR__"npc/obj/iron2");
                ob->move(this_player());
                message_vision(HIG"$N得到了一塊"+ob->query("name")+"！！\n\n"NOR ,me);
                break; 
                case 2:
                ob3=new(__DIR__"npc/obj/sun-stone");
                ob3->move(this_player());
                message_vision(HIG"$N得到了一塊"+ob3->query("name")+"！！\n\n"NOR ,me);
                break;
                case 3:
                ob2=new(__DIR__"npc/obj/moon-stone");
                ob2->move(this_player());
                message_vision(HIG"$N得到了一塊"+ob2->query("name")+"！！\n\n"NOR ,me);
                break;
                } 
                call_out("can_push",120,this_object());
                        }          else{ 
                message_vision("但大石卻沒有絲毫的動靜。\n",me);
              }
          }
          else{
                message_vision("$N突然心血來潮，用雙手灌滿了內勁。\n",me);
                message_vision("只見$N用力的把雙手往大石上搥了下去。\n",me);
                message_vision("也許\是$N的內功\不夠深厚，大石並沒有任何的反應。\n",me);
             }                               
        return 1;
}

void can_push(object tob)
{ 
       int stone = 1;
       return;
} 


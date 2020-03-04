#include <ansi.h>

inherit ROOM;


void create()
{
        set("short", HIB"水寒星洞"NOR);
        set("long", @LONG 
這是一窟幽暗的水洞，水洞上方吊著一條條純白的鐘乳石，滴著小小
水珠，在兩旁，豎立著數條紫水晶，每每互相輝印，照亮水洞的每個大小
角落。中間有一潭水池，潭邊似乎有什麼東西的樣子。
LONG
        ); 
        set("item_desc",([ 
        "水池":"深藍無底的水池，在水池邊緣，竟刻著『水寒星洞』四個 [大字]，且旁邊插著一塊 [木牌]。\n",
        "大字":"『水 寒 星 洞』。 \n",
        "木牌":"一塊木製的牌子，上面寫著 [請勿丟擲火紅果！throw xxx in pool]。\n",
        ]) );
        set("exits", ([ /* sizeof() ==  */ 
        "east" : __DIR__"room19",
]));
        set("no_light",1); 
        set("no_recall",1);
        setup();
} 
void init()
{
     add_action("do_throw","throw");
} 
int do_throw(string arg)

{
             object me,x,fruit,z;           
             me = this_player();  
                             
        if(!arg || arg!="fruit in pool") return notify_fail("你要丟擲什麼?\n");
        if(!objectp(z=present("fire fruit",me) ) )
                return notify_fail("你沒有東西可以丟啊 ? \n");
        message_vision(HIW"$N丟出一顆"HIR"火紅果。\n"NOR,me); 
       {
        destruct(z);
    } 

        me->start_busy(2);
switch (random(30) ){ 
                case 16:
                      message_vision("你忽然聽到一聲：你在幹什麼！！！不是都說不能丟火紅果了！沒看到我立的牌子嘛！！\n",me);
                      write("子黃丹說：好小子•••看我怎麼教訓你！\n");
                      x=new(__DIR__"npc/dan");
                      x->move(this_object());
                      x->kill_ob(this_player()); 
                      me->start_busy(10+random(2));
                      break;
               case 15:
                     message_vision("你看到水池中激起一陣陣澎湃的水花！。\n",me); 
                     message("world:world1:vision", 
                     HIW"\n\t千年神獸•『玄武神龜』重出水池，忽然天降甘霖，久不消退。\n"NOR,users());
                     message_vision("玄武神龜露出一雙水汪汪的大
眼睛，似乎想跟你討東西吃••\n",me);
                     x=new(__DIR__"npc/turtle"); 
                     x->move(this_object());  
                     break;
               case 14:
                     message_vision("忽然一道黑影，疾呼而過，天空彷彿暗了一半••\n",me);
                     message("world:world1:vision", 
                     HIR"\n\t"+me->name(1)+"敵逢百年巨鵰，雙方展開一場激烈廝殺！！\n\n"NOR,users());     
                     x=new(__DIR__"npc/chisel");
                     x->move(this_object());    
                     x->kill_ob(this_player()) ;
                     break;
               case 13:
                     message_vision("當火紅果還在空中時，『咦！』不見了，只聽見一陣怪聲•••\n",me);
                     message("world:world1:vision",
               
      HIG"\n\t妖精商：咯咯咯咯....我有很多寶貝，不是你們人類買得起的...咯咯咯咯..\n\n"NOR,users());      
                     x=new(__DIR__"npc/elf");
                     x->move(this_object());  
        break;  
               case 12:
                     message_vision("火紅果高高的飛在空中，『咚』的一聲，掉進的水裡，並沒產生什麼異狀\n\n",me);
                     break; 
               case 11:
                     message_vision("池中激出朵漂亮的水花,一波波漣漪往四週擴散而去\n"       
                                    "突然!池中浮現一條血紅的身影！\n",me);  
                     message("world:world1:vision", 
  HIY"\n\t【水寒星洞】"+HIR"殘暴血蛟，再出江湖，水洞生物，無一倖免。\n"+NOR,users());                                                x=new(__DIR__"npc/snake");
                        x->move(this_object()); 
                        x->kill_ob(this_player());
                        break; 
                case 10:
                      message_vision("池中激出朵漂亮的水花,一波波漣漪往四週擴散而去\n"
                             "突然!池中浮現一條黃金的身影！\n",me); 
                        message("world:world1:vision", 
  HIC"\n【動作】"+HIY"麒麟魚(Chi lin-fish)"+HIC"對著大家大聲喊道︰Ｈｅｌｌｏ！大家好∼∼ :D。\n"+NOR,users()); 
                       x=new(__DIR__"npc/chi-lin-fish");
                       x->move(this_object()); 
                       break; 
                case 9:
                      message_vision("水潭忽然衝出一隻水鬼！\n"
                      HIW"水鬼眼睛一閃 -_-+，張開血盆大口，往"+me->name()+"咬了下去！！\n" 
                     +HIR"\t傷口深可見骨！！"+NOR,me); 
                      message_vision(""+me->name()+"負傷過重，倒地不起....\n",me);
                      me->start_busy(10);
                      me->receive_damage("hp",500+random(222));
                      me->receive_damage("ap",400+random(111));
                      me->receive_damage("mp",600+random(55));
                      break;
                 }  
        return 1;
}


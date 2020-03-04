#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"破舊的木箱"NOR,({"old box","box"}));
        set("unit", "個");
        set("long",@LONG
一個佈滿蜘蛛網的破舊箱子，木頭都已經腐朽了，也許敲一下就會打開了。
LONG
        );
        set_weight(999999);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_openbox","hit");
}

int do_openbox(string arg)
{
        object obj,me = this_player();
        object room = environment(this_player());
        if(arg != "old box" && arg != "box" && arg != "wood")
          { return notify_fail("你要打開什麼？\n"); }
        if(!me->is_busy() || me->is_fighting())
          { 
              message_vision(HIY"$N試著敲開木箱...\n"NOR,me);
              me->start_busy(7);
              call_out("open",5);
              return 1;
          }
        else
             { return notify_fail("你正在忙！\n"); }
}

void open()
{
        int i,ran,index,amount;
        string msg;
        object obj;
        object ob = this_object();
        object me = this_player();
        
        i = random(100);
        ran = random(10); 
        switch( i ) {
           case 0..5:
                   message_vision(HIR"$N敲開木箱，不過裡面什麼也沒有...\n\n"NOR,me);
                   destruct(ob);
                   break;
           case 6..10:
                   message_vision(HIR"$N敲開木箱，叫了一聲：幹...空的！\n\n"NOR,me);
                   destruct(ob);
                   break;
           case 11..100:
                   message_vision(HIR"木箱被$N敲開了！\n\n"NOR,me);
                   switch( ran ) {
                      case 0:
                             amount = random(20000)+1;
                             obj =  new("/obj/money/coin");
                             obj->set_amount(amount);
                             msg = "掉出"+chinese_number(amount)+"枚古幣";
                             obj->move(environment(me));
                             break;
                      case 1:
                             index = random(50)+1;
                             msg = "掉出"+chinese_number(index)+"碗四神湯";
                             for(i=0;i<index;i++)
                               new("/open/world1/acme/area/npc/obj/soup")->move(environment(me));
                             break;
                      case 2:
                             index = random(30)+1;
                             msg = "掉出"+chinese_number(index)+"片"+HIY"妖精糧食"NOR;
                             for(i=0;i<index;i++)
                               new("/open/world1/moonhide/pool/npc/obj/lbg")->move(environment(me));
                             break;
                      case 3:
                             index = random(30)+1;
                             msg = "掉出"+chinese_number(index)+"顆元氣丸";
                             for(i=0;i<index;i++)
                               new("/open/world1/ksj/east_island/npc/eq/genki-pill")->move(environment(me));
                             break;
                      default:
                             index = random(4)+1;
                             obj = new("/u/f/fedex/area/npc/npc1");
                             message_vision(HIR"箱子裡衝出"+chinese_number(index)+
                             obj->query("unit")+obj->query("name")+"！\n"NOR,obj,me);
                             for(i=0;i<index;i++)
                               new("/u/f/fedex/area/npc/npc1")->move(environment(me));
                      break;
                      }
                      if (ran <=3)
                       { message_vision("\n箱子裡"+msg+"，太神奇了！\n\n",me); }
                      destruct(ob);
            break;
          }
}


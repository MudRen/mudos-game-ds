#include <ansi.h>
inherit NPC;

void create()
{
  set_name("料理鐵人", ({ "food master","master"}));
  set("long",@long
穿著乾淨整齊的中年料理師傅，頭上綁著白色頭巾，手腳俐落地處理
著食材，他是村子裡製作料理的第一把交椅，村民都叫他『鐵人』，
不僅代表他難以被打倒，也表示他對料理的信念與堅持。
long);      
  set("gender", "男性" );
  set("age",42);
  set("level",35);
  set("race","human");
  set("no_fight",1);
  set("talk_reply","您好∼想吃點什麼？請參考牆上的菜單(menu)\n");
  set("chat_chance", 5);
  set("chat_msg", ({
      "料理鐵人比著桌上陳列的海鮮說道：新鮮食材∼現場料理∼\n",
      "料理鐵人身形晃動，雙手快速地操動料理用具，看得你目不暇給。\n",
     }));
  setup();
  add_money("coin",100);
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) 
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_order","order");
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(2) ) 
  {
    case 0:
         say( "料理鐵人一邊切著魚肉一邊說道：客人您好∼歡迎光臨。\n");
         break;
    case 1:
         say( "料理鐵人彎腰說道：客人這邊請坐∼\n");
         break;
  }
}

int do_order(int arg)
{
  object me,ob;
  me = this_player();
  ob = this_object();

  if( !arg )
    return notify_fail("你要點什麼菜呢？(order)\n");
  if( me->query_temp("is_busy/eat_food"))
    return notify_fail("你已經點了東西吃了。\n");

  switch(arg) 
  {
    case "1":
          if( !me->can_afford(30) )
            return notify_fail("你身上的錢不夠。(30文錢)\n");
          me->receive_money(-30);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"蛤吸",me);
          call_out("eatting",4,me);
          call_out("finish",6,"蛤吸",me);
          me->receive_heal("hp",50);
          me->receive_heal("ap",30);
          me->receive_heal("mp",10);
          break;

    case "2":
          if( !me->can_afford(50) )
            return notify_fail("你身上的錢不夠。(50文錢)\n");
          me->receive_money(-50);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"鯛吸",me);
          call_out("eatting",4,me);
          call_out("finish",6,"鯛吸",me);
          me->receive_heal("hp",100);
          me->receive_heal("ap",50);
          break;

    case "3":
          if( !me->can_afford(20) )
            return notify_fail("你身上的錢不夠。(20文錢)\n");
          me->receive_money(-20);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"若芽吸",me);
          call_out("eatting",4,me);
          call_out("finish",6,"若芽吸",me);
          me->receive_heal("hp",30);
          me->receive_heal("ap",20);
          me->receive_heal("mp",10);
          break;

    case "4":
          if( !me->can_afford(40) )
            return notify_fail("你身上的錢不夠。(40文錢)\n");
          me->receive_money(-40);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"海老天",me);
          call_out("eatting",4,me);
          call_out("finish",6,"海老天",me);
          me->receive_heal("hp",80);
          me->receive_heal("ap",40);
          break;

    case "5":
          if( !me->can_afford(25) )
            return notify_fail("你身上的錢不夠。(25文錢)\n");
          me->receive_money(-25);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"野菜天婦羅",me);
          call_out("eatting",4,me);
          call_out("finish",6,"野菜天婦羅",me);
          me->receive_heal("hp",60);
          me->receive_heal("ap",15);
          break;

    case "6":
          if( !me->can_afford(60) )
            return notify_fail("你身上的錢不夠。(60文錢)\n");
          me->receive_money(-60);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"鹽燒",me);
          call_out("eatting",4,me);
          call_out("finish",6,"鹽燒",me);
          me->receive_heal("hp",150);
          me->receive_heal("ap",30);
          break;

    case "7":
          if( !me->can_afford(50) )
            return notify_fail("你身上的錢不夠。(50文錢)\n");
          me->receive_money(-50);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"海老鹽燒",me);
          call_out("eatting",4,me);
          call_out("finish",6,"海老鹽燒",me);
          me->receive_heal("hp",100);
          me->receive_heal("ap",50);
          break;

    case "8":
          if( !me->can_afford(10) )
            return notify_fail("你身上的錢不夠。(10文錢)\n");
          me->receive_money(-10);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"紫蘇梅干",me);
          call_out("eatting",4,me);
          call_out("finish",6,"紫蘇梅干",me);
          me->receive_heal("mp",30);
          break;

    case "9":
          if( !me->can_afford(10) )
            return notify_fail("你身上的錢不夠。(10文錢)\n");
          me->receive_money(-10);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"納豆",me);
          call_out("eatting",4,me);
          call_out("finish",6,"納豆",me);
          me->receive_heal("mp",30);
          break;

    case "10":
          if( !me->can_afford(100) )
            return notify_fail("你身上的錢不夠。(100文錢)\n");
          me->receive_money(-100);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"清酒",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"清酒",me);
          me->receive_heal("ap",100);
          me->receive_heal("mp",200);
          break;

    case "11":
          if( !me->can_afford(130) )
            return notify_fail("你身上的錢不夠。(130文錢)\n");
          me->receive_money(-130);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"燒酒",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"燒酒",me);
          me->receive_heal("ap",140);
          me->receive_heal("mp",250);
          break;

    case "12":
          if( !me->can_afford(150) )
            return notify_fail("你身上的錢不夠。(150文錢)\n");
          me->receive_money(-150);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"梅酒",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"梅酒",me);
          me->receive_heal("ap",150);
          me->receive_heal("mp",300);
          break;

    case "13":
          if( !me->can_afford(300) )
            return notify_fail("你身上的錢不夠。(300文錢)\n");
          me->receive_money(-300);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"純米大吟釀",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"純米大吟釀",me);
          me->receive_heal("ap",300);
          me->receive_heal("mp",600);
          break;

    case "14":
          if( !me->can_afford(180) )
            return notify_fail("你身上的錢不夠。(180文錢)\n");
          me->receive_money(-180);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"壽喜燒",me);
          call_out("eatting",4,me);
          call_out("finish",6,"壽喜燒",me);
          me->receive_heal("hp",400);
          me->receive_heal("ap",80);
          break;

    case "15":
          if( !me->can_afford(180) )
            return notify_fail("你身上的錢不夠。(180文錢)\n");
          me->receive_money(-180);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"涮涮鍋",me);
          call_out("eatting",4,me);
          call_out("finish",6,"涮涮鍋",me);
          me->receive_heal("hp",400);
          me->receive_heal("ap",80);
          break;

    case "16":
          if( !me->can_afford(250) )
            return notify_fail("你身上的錢不夠。(250文錢)\n");
          me->receive_money(-250);
          command("nod "+me->query("id"));
          me->disable_player_cmds("你正在吃東西。\n");
          me->set_temp("is_busy/eat_food","你正在吃東西。");
          me->start_busy(6);
          message_vision("料理鐵人說道：馬上就好，請稍待。\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"河魨鍋",me);
          call_out("eatting",4,me);
          call_out("finish",6,"河魨鍋",me);
          me->receive_heal("hp",500);
          me->receive_heal("ap",200);
          break;

    default:
          write("沒有你要點的菜喔？\n");
          break;
  }
  return 1;
}

void cooking(object me)
{
  if(!me) return;
  tell_object(me,HIG"料理鐵人用俐落的身手迅速將食材處理好，再以純熟的手法進行烹調。\n"NOR);
  return;
}

void giving(string arg,object me)
{
  if(!me) return;
  message_vision("料理鐵人將"HIW+arg+NOR"端到$N的面前。\n",me);
  return;
}

void eatting(object me)
{
  if(!me) return;
  message_vision(HIG"$N坐了下來，細細品嘗所點的食物。\n" NOR,me);
}

void finish(string arg,object me)
{
  if(!me) return;
  message_vision("$N津津有味地將"HIW+arg+NOR"吃得一點不剩。\n",me);
  me->delete_temp("is_busy/eat_food");
  me->enable_player_cmds();
}

void finish_d(string arg,object me)
{
  if(!me) return;
  message_vision("$N將"HIW+arg+NOR"慢慢喝完了。\n",me);
  me->delete_temp("is_busy/eat_food");
  me->enable_player_cmds();
}

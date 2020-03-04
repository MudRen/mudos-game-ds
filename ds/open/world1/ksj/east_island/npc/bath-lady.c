#include <path.h>
inherit NPC;

void create()
{
  set_name("澡堂小姐" , ({ "bath lady","lady" }));
  set("long",@LONG
在湯屋服務的一位年輕的小姐，穿著淡藍色的和服，在櫃台前招呼著
客人，若想洗個溫泉舒緩身心，只要付些錢(pay)就能進去了。
LONG);
  set("chat_chance",9);
  set("chat_msg",({
      "澡堂小姐對你鞠躬說道：您好，這位客人想泡湯(spa)嗎？\n",
     (: command,"smile" :),
     (: command,"say 泡個湯可以解除疲勞喔∼" :),
     (: command,"say 本湯屋的溫泉對於療傷鎮痛也有功\效喔∼" :),
     }));
  set("inquiry",([
      "泡湯" : "泡湯(spa)一次 300 文錢∼！\n",
     ]));
  set("no_fight",1);
  setup();
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
  add_action("do_pay","pay");
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(2) )
  {
    case 0:
      say( "澡堂小姐朝著你的方向鞠躬說道：歡迎光臨。\n");
      break;
    case 1:
      say( "澡堂小姐對你說道：客人想泡個舒服的湯嗎？\n");
      break;
  }
}

int do_pay(string arg)
{
  object me,ob;
  string c;
  me = this_player();
  ob = this_object();

  if( !arg || sscanf(arg,"for %s",c)!=1 )
    return notify_fail("澡堂小姐疑惑地說道：客人是要泡湯嗎？(pay for spa)\n");

  switch(c)
  {
    case "spa":
      if( !me->can_afford(300) )
        return notify_fail("你身上的錢不夠喔。(300文錢)\n");
      me->receive_money(-300);
      me->add_temp("bathe",1);
      message_vision("$N付給了$n泡湯一次的費用，總共三百文錢。\n",me,ob);
      command("nod "+me->query("id"));
      command("say 這位客人請往裡面走(enter)");
      break;
    default:
      write("您是要泡湯(spa)嗎？\n");
      break;
  }
  return 1;
}

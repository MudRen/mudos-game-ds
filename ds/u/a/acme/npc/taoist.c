#include <ansi.h>
inherit NPC;
void create()
{
        set_name("清禪道長" ,({ "taoist" }) );
        set("level",15);
         set("race","人類");
         set("gender","男性");
        set("age", 35);
        set("long", "他是專門降妖伏魔的道長，他衣服已被血染成鮮紅色。\n");
        set_skill("dodge",40);
            set_skill("sword",30);
        set_skill("parry",20);
        set("evil",0);
        set("talk_reply","你能幫忙打探家師的消息嗎？\n");
        set("inquiry/家師","家師三個月前因事外出，至今仍未消息，唉∼∼\n");
        set("limbs", ({ "頭部", "身體", "左腳", "右腳", "後心" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        set("chat_chance", 4);
        set("chat_msg",({
               "清禪道長說道：唉，天殺的殭屍，竟如此的厲害，連我也沒輒...\n"
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (:command("exert hungchen-sword"):),
                "清禪道長喝道：賊子！！！！找死？？？\n",
                "清禪道長說道：咱們無冤無仇，就此罷手如何？\n",
        }) );
        setup();
}
int accept_object(object who,object ob)
{
  object me;
  object pike;
  me=this_player();
  if(ob->name()!="紙")
  {
if(ob->name()!="天師桃木劍")
{
      command("eh");
      command("say 我不須要這種東西。");
      return 0;
     }
else {
      me->set_temp("GETwp/feipike",1);
      command("say 咦！！這不是恩師的寶劍嗎！！");
      say(YEL"清禪道長顫抖著聲音道：恩師寶劍從不離身的，難道∼∼難道∼∼\n"NOR);
  command("fear");
  say(YEL "清禪道長說：這位" + RANK_D->query_respect(ob) + "能告訴我恩師在哪嗎？\n" NOR);
  return 1;
}
  }
  else {
    if(me->query_temp("GETwp/feipike")>0)
    {
      say("清禪道長仔細的看了看這張紙。\n");
      say(YEL"清禪道長大叫：啊∼∼恩師…恩師他…。\n"NOR);
      command("cry");
      say(YEL"清禪道長恨恨的道：這個賊邪佬，哼！！！遲早要為師報仇。\n"NOR);
      command("sob");
      me->delete_temp("GETwp");
      say(YEL"清禪道長說：這位" + RANK_D->query_respect(ob) + "前幾日我叫人打了一把長槍，這長槍可是用精鋼鍊造而成，我這就送你吧。\n"NOR);
         message_vision("清禪道長給$N一把飛震槍。\n",me);
         pike=new(__DIR__"wp/pike");
         pike->move(who);
         command("bow");
       return 1;
    }
  }
}

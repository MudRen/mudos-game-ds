#include <ansi.h>
inherit NPC;
void create()
{
      set_name(HIR"變相"BLK"天魔"NOR,({"kfo evil","evil"}));
      set("class","kfo_evil");
      set("title",HIY"阿修羅密使"NOR);
      set("nickname",HIW"封印解除"NOR);
      set("race","人類");
      set("gender","男性");
      set("age",20);
      set("combat_exp",15000);
      set("score",5000);
      set("int",30);
      set("dex",30);
      set("con",30);
      set("luc",30);
      set("spi",30);
      set("attitude","peaceful");


      set("max_kee",2000);
      set("max_sen",1200);
      set("max_gin",1300);
      set("atman", 4000);
      set("max_atman", 4000);
      set("mana", 4000);
      set("max_mana", 4000);
      set("mana_factor", 5);

      set("apprentice_available", 3);
      set("chat_chance",10);
      set("chat_msg",({
      "別吵我!\n",
      "滾啦!",
      (: command,"pk":),
      (: command,"pk":),
      }));
      set("env/wimpy",70);
      set("inquiry",([
      "藍道天魔" : "他是我的偶像喔",
      "佩麟" : "我粉喜歡她，但也只是過去了！",
      ]));
      set("chat_chance_combat",200);
      set("chat_msg_combat", ({
      (: command,"exert recover":),
      }));
      setup();
      carry_object("obj/staff2")->wield();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 殺！");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 我不收了！滾！;
        }
}
       setup();
  }


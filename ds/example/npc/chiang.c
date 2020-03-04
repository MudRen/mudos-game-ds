#include <ansi.h>
inherit NPC;
void create()
{
 set_name("江清流",({"chiang chin liu","chiang","chin","liu"}));
 set("long","他就是尉遲妄的大弟子----江清流, 號稱十萬俠首, 不過\n"
            "你看他愁眉不展的.顯然遇到了極大的困難.\n"
     );
 set("attitude","peaceful"); 
 set("age",43);
 set("gender","男性");
 set("level",25);
 set("title",HIR"十萬俠首"NOR);
 set_skill("dagger",90);
 set_skill("sky-dagger",90);
 set("chat_chance",5);
 set("chat_msg", ({"江清流嘆了口長氣.... \n",
                   "江清流嘆口氣說:真是一隻神鷹打翻一船人啊....\n",
                   "江清流接著說:可是我們哪裡沒搜過?....\n",
                   "江清流忽然說道:莫非又回到參天古木上神鷹穴了?....\n"
}));
setup(); 
carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/sob_dagger")->wield();
}

void meet_eagle()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("meet_eagle");
      switch( i ) {
          case 1:
            command("say 啊! 這不是神鷹的鷹羽嗎?");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此鷹羽的？");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 2:
            message_vision(YEL"$N將得到鷹羽的過程告訴江清流。\n"NOR,me);
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 3:
	    command("nod");
            command("say 原來如此...。");
            command("hoho");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle"t",3,me);
            break;
          case 4:
            if(me->query_skill("sky-dagger") == 0) 

            {
              command("say 師父常說: 這套匕法可傳可接近鳥之人...");
              command("say 如大俠不嫌棄,就請大俠一觀!.");
              obj->delete_temp("meet_eagle");
            }
            else {
              command("say 只可惜在下無以為報...請受在下一拜.");
	      command("bow");
              obj->set_temp("meet_eagle",i+1);
              call_out("meet_eagle",2,me);
            }
            break;
          case 5:
            message_vision(YEL"江清流將天嘯匕法的基本心訣講解給$N聽.\n"NOR,me);
            message_vision(HIY"(~~~~~一~~~~~個~~~~~時~~~~~辰~~~~~過~~~~~去~~~~~了~~~~~)\n"NOR,me);
	    message_vision(HIY"江清流說道:大俠果是奇人, 這天嘯匕法竟能如此快的領悟!!\n"NOR,me);

            command("cong"+me->query("id"));
	    command("smile");
            me->set_skill("sky-dagger",5);
            obj->delete_temp("meet_eagle");
            break;
      }
}
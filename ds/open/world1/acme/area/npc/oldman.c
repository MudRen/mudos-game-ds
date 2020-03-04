#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黑衣老人" ,({ "old man","man" }) );
        set("level",55);
        set("race","人類");
        set("gender","男性");
        set("age", 90);
        set("long", "他是一位勁裝束衣的黑衣老人。\n");
        set("int",100);
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("sword",120);
        set_skill("parry",100);
        set_skill("dodge",110);
        set_skill("godsword",110);
        set_skill("mirage-steps",100);
        set("chat_chance", 10);
        set("chat_msg",({
           (:command("exert mirage-steps"):),
           (:command("exert godsword"):),
        }) );
        set("chat_chance_combat",120);
        set("chat_msg_combat", ({
                  (:command("cast god-fire"):),
                  (:command("cast godbenison"):),
                  (:command("cast godbenison"):),
                  (:command("cast godbenison"):),
                  (:command("cast god-fire"):),
        }) );
        set("talk_reply","你能幫小老兒一點小忙(help)嗎？\n");
        set("inquiry/help","你若能找出天池發光的原因，自然有你的好處。\n");
        setup();
        add_money("coin",100);
        carry_object(__DIR__"wp/longsword.c")->wield();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="夜明珠")
        {
           command("slap "+who->query("id"));
           command("say 你當我是撿破爛的呀。....（-.-）凸");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
message_vision("$N給了黑衣老人一個"+ob->query("name")+"。\n",who);
             command("hmm");
             obj->start_busy(10);
             obj->set_temp("giveplate",1);
             destruct(ob);
             call_out("giveplate",1,who);
             return 1;
        }
}
void giveplate()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveplate");
      switch( i ) {
          case 1:
            say(HIY"黑衣老人仔細瞧了瞧這顆小珠子。\n"NOR);
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 2:
            command("say 原來這小東西就是使得天池在晚間發光的呀。");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",2,me);
            break;
          case 3:
            say(HIY"黑衣老人拿著夜明珠在手上把玩，甚是喜愛。\n"NOR);
            command("smile");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 4:
            command("say 老夫生平最喜歡收藏珍奇古物了，得此明珠，此生值得啊！");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 5:
            command("say 這樣吧！這個令牌給你。");
            command("say 以後有何困難，可亮出此令牌，別人也畏敬你三分呀。");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/plate");
            plate->move(obj);
            command("give plate to "+ me->query("id") );
            obj->delete_temp("giveplate");
            break;
          }
}

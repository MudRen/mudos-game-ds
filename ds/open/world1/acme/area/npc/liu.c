// Write by -Acme-
// Update by -Acme- add AI

#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
object liu=this_object();
void create()
{
        set_name("流無形" , ({ "invisible liu","liu" }) );
        set("long",@long
他是ξ神武教ξ的教主，是威震武林的武林天尊，但卻生得慈眉
善目的，毫無驕矜之態。你可以和他一起討論武術之事。
long
);
        create_family( HIC "ξ神武教ξ" NOR ,2,"教主");
        set("level",42);
        set("race","人類");
        set("age",65);
        set("nickname","孤獨一方");
        set("adv_class",1);
        set("class1","神武教");
        set("gender","男性");
        // 設定屬性分配表, 每一項的值在負9至正10之間
        // 而且四項的總和要剛好等於 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("int",100);
        set("con",70);
        set("str",40);
        set("dex",75);
        set_temp("apply/hit",50);
        set_temp("apply/dodge",70);

        set("guild_skills",([
               "dodge" : ({120,3,70}),
               "parry" : ({130,2,60}),
               "sword" : ({130,3,70}),
               "godsword" : ({140,2,80}),
               "meditate" : ({120,3,80}),
               "mirage-steps" : ({140,3,80}),
        ])  );
        set("guild_spells",([
               "god-fire" : ({130,3,90}),
//               "god-benison":({170,2,50}),
               "summon_ghost" : ({130,3,90}),
        ]) );
        set_spell("god-fire",100);
        set_spell("god-shield",100);
        set_spell("god-benison",99);
        set_spell("summon_ghost",90);
        set_skill("meditate",100);
        set_skill("bloodsky-force", 90);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
        set("addition_damage",45);
        set("addition_armor",50);
        set("no_check_class",1);

        set("talk_reply","唉∼師父他老人家已二三年未通消息，如今不知安好.....");
        set("inquiry/武術","神武教的武功\可分為三類，第一是「氣」、第二是「猛」，第三則是「御」。\n");
        set("inquiry/氣","「氣」是指神武教的內功\「血蒼穹」，但以目前的你是無法習得的。\n");
        set("inquiry/猛","「猛」是指神武教的法術類的，只要你智慧高，使將起來，可是威猛無比。\n");
        set("inquiry/御","「御」是指神武教的控鬼之術，控制好的話，鬼可是無所不能的。\n");
        set("chat_chance", 20);
        set("chat_msg",({
                (: normal_ai() :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        setup();
        carry_object(__DIR__"wp/godsword.c")->wield();
        carry_object(__DIR__"eq/godneck.c")->wear();
        carry_object(__DIR__"eq/godarmor.c")->wear();
        carry_object(__DIR__"eq/godboots.c")->wear();
        carry_object(__DIR__"eq/godcloth.c")->wear();
        carry_object(__DIR__"eq/godhands.c")->wear();
        carry_object(__DIR__"eq/godhead.c")->wear();
        carry_object(__DIR__"eq/godlegging.c")->wear();
        carry_object(__DIR__"eq/godmask.c")->wear();
        carry_object(__DIR__"eq/godpants.c")->wear();
        carry_object(__DIR__"eq/godring.c")->wear();
        carry_object(__DIR__"eq/godsurcoat.c")->wear();
        carry_object(__DIR__"eq/godwaist.c")->wear();
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_ap.c");
        map_skill("dodge","mirage-steps");
}

void normal_ai()
{
        /* 沒裝備盾，則裝盾 */
        if( !liu->query_temp("armor/shield") )
                command("wear all");

        /* 沒有exert gosword 則,exert godsword */
        if( !liu->query_skill_mapped("sword") )
                command("exert godsword");      

        /* 招出神武盾 (cast god-shield) */
        if( !liu->query_temp("armor/shield") && ( liu->query("mp") > liu->query("max_mp")/2 ) )
                command("cast god-shield");

        /* 受傷時會恢復血 (exert bloodsky-force heal) */
        if( (liu->query("hp") + 200 < liu->query("max_hp") ) && liu->query("ap") > 50 )
                command("exert bloodsky-force heal");

        /* 恢復內力 (eat ap pill) */
        if( liu->query("ap") < liu->query("max_ap")/4*3 )
                command("eat ap pill");

        /* mp極少時會冥思增加mp (exert meditate) */
        if( (liu->query("mp") < liu->query("max_mp")/5 ) && liu->query("hp") > 1500 )
                command("exert meditate");

        return;
}
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(liu));

        /* 武器被打掉，則裝回去 */
        if( !liu->query_temp("weapon") ) 
                command("wield sword");

        /* 沒裝備盾，則裝盾 */
        if( !liu->query_temp("armor/shield") )
                command("wear shield");

        /* 沒有exert gosword 則,exert godsword */
        if( !liu->query_skill_mapped("sword") )
                command("exert godsword");      

        /* 受傷時會恢復血 (eat hp pill) */
        if( liu->query("hp") + 1000 < liu->query("max_hp") )
                command("eat hp pill");

        /* 恢復魔力 (eat mp pill) */
        if( liu->query("mp") + 1000 < liu->query("max_mp") )
                command("eat mp pill");

        /* 恢復內力 (eat ap pill) */
        if( liu->query("ap") < liu->query("max_ap")/4*3 )
                command("eat ap pill");


        /* 敵人busy 就放火
           或者自身ap不夠無法用godsword特攻也放火
           或者自身hp不夠則狂放火以自保
        */
        i=sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( target[i]->is_busy()
                            || (liu->query("ap") < liu->query("max_ap")/4*3)
                           || (liu->query("hp") < liu->query("max_hp")/2 ) )
                             if( userp(target[i]) ) command("cast god-fire on " + getuid(target[i]) );
                               else command("cast god-fire on " + target[i]->query("id") );
                }
        }
        return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="神武令牌")
        {
                command("? "+who->query("id"));
                command("say 在下並不需要這個東西。");
                return 0;
        }
        else {
                if( obj->is_busy() || obj->is_fighting() || obj->query_temp("addsenwu") )
                {
                        command("whisper "+who->query("id")+" 我正在忙，請"+who->query("name")+"等一下。");
                        return 0;
                }
                message_vision("$N給了流無形一個"+ob->query("name")+"。\n",who);
                obj->set_temp("addsenwu",1);
                destruct(ob);
                call_out("addsenwu",1,obj);
                return 1;
        }
        return 1;
}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}
void addsenwu()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("addsenwu");
      switch( i ) {
          case 1:
            command("say 咦！！這不是師父的令牌嗎！！");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此令牌的？");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 2:
            message_vision(YEL"$N說：這是尊師托我交給您的，並說他老人家逍遙自在，您不用擔心了。\n"NOR,me);
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 3:
            command("say 原來師父安好，看來我是多擔心了。");
            command("smile");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say 這位" +  RANK_D->query_respect(me) + "多謝幫忙。");
              command("bow "+me->query("id"));
              obj->delete_temp("giveplate");
            }
            else {
              command("say 我看你這"+ RANK_D->query_respect(me) + "蠻順眼的，這樣吧！老夫就收你為徒！");
              obj->set_temp("addsenwu",i+1);
              call_out("addsenwu",2,me);
            }
            break;
          case 5:
            command("say 入我教當行俠仗義，除強濟弱！");
            message_vision(YEL"$N跪下來說道：師父！弟子必定遵照師父的教誨！\n"NOR,me);
            message_vision(HIY"流無形輕輕地拍拍$N的頭，並說道：好！好！..\n"NOR,me);
            command("pat "+me->query("id"));
            me->set("adv_class",1);
            me->set("class1","神武教");
            me->create_family("神武教",3,"教徒");
        me->set("guild_rank","神武教第三代教徒");
            me->set("guild_gifts", ({2,4,9,5}) );

            obj->delete_temp("addsenwu");
            break;
      }
}
int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//      return 1;

}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
          if( !userp(me) ) return 0;
        if(me->query("class1")=="神武教") return notify_fail("你已是神武教弟子了。\n");
        if(arg!="神武教") return notify_fail("你要拜入那一個門派?\n");
        say("流無形正自發愁，並沒有發現你要加入。\n");
        say("流無形喃喃自語的道：師父他老人家不知安好，已十年八戴未通消息。\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
          if (me->query("level") > 25 ) return notify_fail("你並不是流無形的弟子。\n");   //by tmr
        if (me->query("family/family_name")=="神武教") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是神武教徒。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message_vision(HIR"\n\t\t$N大喝一聲，在瀕死之前使出最後一招！！\n"NOR,this_object());
        message_vision(HIW"\n$N劍走輕靈，東一招、西一招的誘使$n產生破綻！！\n"NOR,this_object(),ob);
        message_vision(GRN"\t(登時$n心神不定，開始露出破綻！！)\n"NOR,this_object(),ob);
//        ob->start_busy(3);
        message_vision("$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"HIW"」\n"NOR,this_object());
        message_vision(HIR"\t只見$n閃躲不掉一道"HIW"『"HIR"神武真火"HIW"』"HIR"的攻勢，被燒得皮開肉綻！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        message_vision(HIW"剎那間！！$N的背後出現數道"HIR"火龍"HIW"，飛騰而出，直衝向$n！！\n"NOR,this_object(),ob);
        message_vision(HIR"\t只見$n一時反應不過來，慘叫一聲，被火龍給吞噬了！！\n"NOR,this_object(),ob);
        ob->receive_damage("hp",ob->query("hp")*19/20);
        COMBAT_D->report_status(ob);
        message("world:world1:vision",
                CYN"\n  武林傳出了一則驚人的消息:\n\n\t武林泰斗「獨孤一方」流無形終於敗給了"
                +ob->name(1)+"。\n\n"+NOR,users());
        ob->add("popularity", 5); //聲望
        tell_object(ob,HIW"(因為你殺死了流無形，所以得到了 5 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void soldier_assist(object alert, object me)
{
        if( !living(this_object()) || is_fighting(me) )
                return;
        kill_ob(me);
        me->fight_ob(this_object());
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = "神武教第三代教徒"; break;
                        case 1: rank = "神武教第三代教徒"; break;
                        case 2: rank = "神武教之烈焰破空"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "神武教第三代教徒"; break;
                        case 1: rank = "神武教第三代教徒"; break;
                        case 2: rank = "神武教之烈焰破空"; break;
                }
        }
        return rank;
}

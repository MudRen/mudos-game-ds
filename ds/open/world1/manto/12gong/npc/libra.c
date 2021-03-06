inherit NPC;
#include <ansi2.h>;
void powerup();

void create()
{
        set_name(HIG"亞斯托雷斯"NOR, ({"astraea"}));
        set("long", "一隻手持秤，一隻手握斬除邪惡的劍的正義女神。\n");
        set("gender","女性");
        set("title", HIW"【正義女神】"NOR);
        set("level", 65);
        set("age",37);
        set("attitude", "friendly");
        set("race","human");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set("max_mp", 7000);
        set("max_ap", 5000);

        set_temp("fly",1);
        set_temp("apply/damage",220);
        set_temp("apply/armor", 260);
        set_temp("apply/hit", 70);
        set_temp("apply/dodge", 50);
        set("addition_armor", 80);

        setup();
        set_temp("apply/tec", 5);
       set_temp("apply/bar", 5);
        set_temp("apply/wit", 8);
        set_temp("apply/bio", 5);
        //carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object(__DIR__"wp/longsword")->wield();
}

void powerup()
{
        message_vision("$N大喝：小宇宙！爆發吧！\n",this_object());
        this_object()->set("hp",query("max_hp"));
        this_object()->set("mp",query("max_mp"));
        this_object()->set("ap",query("max_ap"));
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        return;
}

int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;
     switch(random(6))
     {
        case 0:
        {
        message_vision(HIC"$N高喊一聲咒語，九天之中竄出道道颶風，直飛$n！\n",me,target);
        if(random(2))
                {
              message_vision(HIC"$N被風吹的跪在地上，毫無半點力量！"HIR"("+query("max_hp")/20+")\n"NOR,target,me);
              target->receive_damage("hp",query("max_hp")/20);
              target->receive_damage("mp",query("max_mp")/10);
        COMBAT_D->report_status(target);
        me->start_busy(2);
                }
        else
        message_vision(HIG"$N身型急轉，不知道繞了多少圈才奪過颶風的攻擊！\n"NOR,target);
        }
        break;
        case 1:
        {
         message_vision(YEL"$N高喊一聲咒語，一條水龍自濺底而出，尾巴向$n掃去！\n",me,target);
        if(random(2))
                {
              message_vision(GRN"$N被水龍的尾巴甩了個正著，$N頓時眼冒金星！"HIR"("+2*query("max_hp")/15+")\n"NOR,target);
          target->receive_damage("mp",2*query("max_mp")/15);
          target->receive_damage("ap",2*query("max_ap")/10);
        COMBAT_D->report_status(target);
        me->start_busy(2);
                }
        else
        message_vision(HIY"$N用盡全身力氣，飛昇而氣，水龍的尾巴正從$N的腳底板掃過！\n"NOR,target);
        }
        break;
        case 2:
        {
        message_vision(HIR"$N高喊一聲咒語，大地震抖，無數土龍突然向$n衝過來！\n",me,target);
                if(random(2)==0)
                {
              message_vision(HIR"$N如一個球一樣，被無數只土龍在空中戲弄著！"HIR"("+3*query("max_hp")/20+")\n"NOR,target);
              target->receive_damage("mp",3*query("max_mp")/20);
              target->receive_damage("ap",3*query("max_ap")/20);
              COMBAT_D->report_status(target);
                }
        else
        message_vision(HIR"$N看準了土龍之間的空隙，左轉右轉，才勉強離難！\n"NOR,target);
        }
        break;
  }
        return 0;
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");

        if( !objectp(who) ) return damage;
        if( environment(this_object()) != environment(who) ) return 0;
        if( objectp(who) && type=="hp")
        set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");

        if(random(100)<50)
        {
            damage=1;
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 30 ) 
            {
                sw->unequip();
                message_vision(HIY"\n亞斯托雷斯大喝一聲，$N"HIY"頓時被驚的手中一顫，亞斯托雷斯順勢重擊$n。\n" NOR,who,sw);
                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
            } if(random(100) < 50 ) {
                message_vision(HIY "\n亞斯托雷斯身上盔甲泛出金色奇異魔紋，$N"HIY"眼前一花，已被鬥氣重擊多次。\n" NOR,who);
                who->start_busy(2);
            } else {
                message_vision(HIM "\n$n"HIM"驟然發現，剛才交手的竟然是魔法幻影。\n" NOR,this_object(),who);
            }
        }

        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);
        return damage;
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
        ob->start_busy(3);
        message("channel:chat",HIY+"【黃金十二宮】"HIC"雅典娜(Athena)："+ob->name()+
        "闖過了"+environment(ob)->query("short")+"\n"NOR,users());
        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        //ob->set("12gong/libra","done");
        //ob->add("12gong/libra",1);
        //ob->set("title",HIW"天坪座戰士"NOR);
        //ob->save();
        }
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}

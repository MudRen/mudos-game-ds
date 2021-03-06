inherit NPC;
#include <ansi2.h>;

void haltbusy()
{
       if( random(3) ) return;
       message_vision("$N額上的神紋發出陣陣光芒擴散開來。\n",this_object());
       message_vision("$N的身軀從僵硬恢復了過來。\n",this_object());
       this_object()->add_busy(-5);
       return;
}

void powerup()
{
        if( !this_object()->query_temp("pill") ) return;
        if( this_object()->query("hp") >  this_object()->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N大喝：雅典娜，賜予我力量吧！\n", this_object());
        else message_vision("$N大喝：小宇宙！爆發吧！\n", this_object());
        this_object()->receive_heal("hp",query("max_hp")/2);
        this_object()->receive_heal("mp",query("max_mp")/2);
        this_object()->receive_heal("ap",query("max_ap")/2);
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        this_object()->add_temp("pill",-1);
        return;
}

void create()
{
        set_name(HIG"阿爾特隬斯"NOR, ({"artemis"}));
        set("long", "傳說中的狩獵女神－阿爾特隬斯，守護著巨蟹座。\n");
        set("gender","女性");
        set("title", HIG"【狩獵女神】"NOR);
        set("level", 55);
        set("age",26);
        set("attitude", "friendly");
        set("race","nightelf");

        set("chat_chance_combat",80);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("bow", 200);
        set_skill("doubleshoot", 100);
        
        map_skill("bow","doubleshoot");

        set("max_hp", 28000);
        set("max_mp", 7000);
        set("max_ap", 5500);
        
        set_temp("pill", 3);
        set_temp("fly",1);
        set_temp("apply/damage",200);
        set_temp("apply/shield",50);
        set_temp("apply/armor", 290);
        set_temp("apply/hit", 70);
        set_temp("apply/dodge", 50);
        set("addition_armor", 50);

        setup();
        set_temp("apply/bio", 7+random(3));
        set_temp("apply/bar", -1);
        set_temp("apply/wit", -3);
        set_temp("apply/sou", -4);
        carry_object(__DIR__"wp/typhon_bane")->wield();
}

int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;

     switch(random(4))
     {
        case 0:
        {
        message_vision(HIC"$N輕柔的呼喚了幾聲，四周的叢林中出現了大批野獸朝$n衝去！\n",me,target);
        if(random(2))
                {
              message_vision(HIC"$N被撞了個措手不及，身形搖晃欲墜！"HIR"("+query("max_mp")/10+")\n"NOR,target,me);
              target->receive_damage("mp",query("max_mp")/10);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIG"$N一聲輕笑，躲開了這大批獸潮！\n"NOR,target);
        }
        break;
        case 1:
        {
         message_vision(HIC"$N眼望天空，一輪圓月忽然出現在$n的面前！\n",me,target);
        if(random(2))
                {
                message_vision(HIC"這輪銀月竟鋒利無比，$N的身上被劃了一大血口！"HIR"("+query("max_ap")/10+")\n"NOR,target);
                target->receive_damage("ap",query("max_ap")/10);
                COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIC"$N躲避及時，銀月在地上崩出了一道裂痕。\n"NOR,target);
        }
        break;
        case 2:
        {
        message_vision(HIR"$N快速地朝$n射出幾隻永恆之箭！\n",me,target);
                if(random(2)==0)
                {
                message_vision(HIR"$N躲避不急，被永恆之箭狠狠的洞穿而過！"HIR"("+3*query("max_ap")/20+")\n"NOR,target);
                target->receive_damage("mp",3*query("max_mp")/20);
                target->receive_damage("ap",3*query("max_ap")/20);
                COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
               me->start_busy(1);
                }
        else
        message_vision(HIR"$N手忙腳亂勉強躲開了箭矢！\n"NOR,target);
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
        
        haltbusy();
        
        if(random(100)<45)
        {
            damage=1;
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 30 ) 
            {
                sw->unequip();
                message_vision(HIY"\n阿爾特隬斯大喝一聲，$N"HIY"頓時被驚的手中一顫，亞斯托雷斯順勢重擊$n。\n" NOR,who,sw);
                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
            } if(random(100) < 60 ) {
                message_vision(HIY "\n阿爾特隬斯身上盔甲泛出金色奇異魔紋，$N"HIY"眼前一花，已被鬥氣重擊多次。\n" NOR,who);
                who->start_busy(1);
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
        "闖過了"+environment(this_object())->query("short")+"\n"NOR,users());
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

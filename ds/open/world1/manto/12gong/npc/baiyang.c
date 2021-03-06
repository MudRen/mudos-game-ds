inherit NPC;
#include <ansi2.h>

void combat_ai();

void attacked(object me, object target, int damage1, int damage2, int damage3)
{
     target->receive_damage("hp",damage1);
     target->receive_damage("mp",damage2);
     target->receive_damage("ap",damage3);
     COMBAT_D->report_status(target);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
     return;
}

void haltbusy()
{
       if( !random(3) ) return;
       message_vision(HIY"\n$N額上的神紋發出陣陣光芒擴散開來，$N的身軀從僵硬恢復了過來。\n"NOR,this_object());
       this_object()->add_busy(-10);
       combat_ai();
       return;
}

void combat_ai()
{
     object *target, me, weapon;
     int damage, i;
     target = all_inventory(environment(this_object()));
     me = this_object();
     weapon = me->query_temp("weapon");
     if(!target) return;

     if( me->is_busy() ) haltbusy();

     i=sizeof(target);
     while( i-- ) {
            if( this_object()->is_killing(target[i]) || this_object()->is_fighting(target[i]) ){
                switch( random(3))
                {
                        case 0:
                             damage = target[i]->query("max_hp")/8;
                             message_vision(HIR"\n$N"HIR"雙手一揮，一團烈火直衝$n而去，",me,target[i]);
                             if(random(3)) {
                                           message_vision(HIR"$N被$n"HIR"的烈火燒個焦頭焦臉！"HIR"("+damage+")\n"NOR,target[i],me);
                                           attacked(me, target[i], damage, damage, 0);
                                           } else message_vision(HIR"$N輕而易舉的躲過了$n"HIR"的攻擊！\n"NOR,target[i],me);
                        break;
                        
                        case 1:
                             damage = target[i]->query("max_hp")/7;
                             message_vision(HIR"$N"HIR"吹了起橫笛，頓時一隻白羊向$n直衝而去！\n",me,target[i]);
                             if(random(5)) {
                                           message_vision(HIR"$N"HIR"被白羊撞了個人仰馬翻！"HIR"("+damage+")\n"NOR,target[i]);
                                           attacked(me, target[i], damage, 0, damage/2);
                                           } else message_vision(HIR"$N對著白羊大喝一聲：停！白羊乖乖從旁邊溜開了！\n"NOR,target[i]);
                        break;
                        default:
                                damage = target[i]->query("max_mp")/10;
                                if( !weapon ) return;
                                message_vision(HIR"\n$N"HIR"手中的"+weapon->query("name")+HIR"變得碩大無比，直劈$n後腰，",me,target[i]);
                                if(random(8)) {
                                              message_vision(HIR"$N頓時血流如注，頃刻染紅了全身！"HIR"("+damage+")\n"NOR,target[i]);
                                              attacked(me, target[i], 0, damage, damage);
                                              } else message_vision(HIR"$N順著劈來的方向，縱身躍起，躲過這致命一擊！\n"NOR,target[i]);
                        break;
                }
            }
     } 

        if( !me->query_temp("pill") ) return;
        if( me->query("hp") >  me->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N大喝：雅典娜，賜予我力量吧！\n", me);
        else message_vision("$N大喝：小宇宙！爆發吧！\n", me);
        me->receive_heal("hp",query("max_hp")/2);
        me->receive_heal("mp",query("max_mp")/2);
        me->receive_heal("ap",query("max_ap")/2);
        me->clean_condition();
        COMBAT_D->report_status(me);
        me->add_temp("pill",-1);
        return;
}

void create()
{
        set_name(WHT"阿瑞斯"NOR, ({"ares"}));
        set("title", HIR"【戰神】"NOR);
        set("long", "傳說中的戰神阿雷斯，守護著白羊座\n");
        set("gender","男性");
        set("level", 55);
        set("age",37);
        set("attitude", "friendly");
        set("int",95);
        set("race","ogre");
        set("chat_chance_combat",200);
        set("chat_msg_combat",({
            (: combat_ai :),
        }));

        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("axe", 100);

        set("max_hp",25000);

         set_temp("pill", 1);
        set_temp("fly",1);
        
        add("addition_damage",170+random(70));
        add("addition_armor", 190+random(80));
        add("addition_shield", 10);
        
        setup();
      
        set_temp("apply/hit",80+random(30));
        set_temp("apply/dodge",40+random(20));

        set_temp("apply/tec", 3);
        set_temp("apply/bar", 7);
        set_temp("apply/bio", -4);
        set_temp("apply/sou", -2);
        set_temp("apply/wit", -2);

        carry_object(__DIR__"wp/barbarian_axe")->wield();
        carry_object(__DIR__"eq/war_plate")->wear();
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

        if(random(100) > 70)
        {
            damage=1;
            if( is_busy() ) haltbusy();
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 70 ) 
            {
                sw->unequip();
                message_vision(HIY"\n阿雷斯大喝一聲，$N"HIY"頓時被驚的手中一顫，阿雷斯順勢重擊$n。\n" NOR,who,sw);
                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
            } if(random(100) < 40 ) {
                message_vision(HIY "\n阿雷斯身上盔甲泛出金色奇異魔紋，$N"HIY"眼前一花，已被鬥氣重擊多次。\n" NOR,who);
                who->add_busy(2);
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
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}


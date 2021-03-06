/* 向雲堂內功：凝雲心法(cloudforce) 由 Linjack 改自 Cominging 之 Moon_force 於 7/24 */
#include <ansi.h>
inherit SKILL;
void delay(object me);
int exert(object me,object target, string arg)
{
        int heal,reheal,sk,lv,shield,ap,downsh;
        if( arg=="off" )
        {
                if( me->query_skill_mapped("force")!="cloudforce" )
                        return notify_fail("你並沒有在練習凝雲心法。\n");
                me->delete_temp("is_busy/cloudforce");
                message_vision(HIC"\n$N氣凝天靈，散去任督二脈之氣，停止修練凝雲心法。\n"NOR,me);
                me->map_skill("force");
                return 1;
        }
        if( arg=="refresh" )
        {
                if( me->is_ghost() )
                        return notify_fail("\n你現在可是鬼呀！怎麼轉運內息啊？\n");
                if( me->is_fighting() )
                        return notify_fail("\n真敬佩你的勇氣，不怕轉到岔氣的怪物。\n");
                if( me->is_busy() )
                        return notify_fail("\n先等你做完手邊的事再說吧。\n");
                if( me->query_skill_mapped("force")=="cloudforce" )
                        return notify_fail("\n你仍在修煉 (或使用) 凝雲心法之中喔。\n");        
                if( me->query("mp") < 50 )
                        return notify_fail("\n老兄，你已經沒有足夠的精神力了吧。\n");
                if( me->query("ap") >= me->query("max_ap") )
                        return notify_fail("\n老兄，你太奇怪了吧，內力飽滿了還轉運內息做什麼？\n");
                if( me->query_skill("cloudforce") < 10 )
                        return notify_fail("\n你的凝雲心法根底不足，無法將精神力轉為內力喔。\n");
                heal= (int)me->query("max_ap");
                sk = (int)me->query_skill("cloudforce");
                lv = (int)me->query("level");
                if ( sk > 40 ) sk = 40 + ((sk-40)/2);
                reheal = (heal / 15) + (sk/2) + random(5) + (lv/2);
                me->receive_heal("ap",(reheal*3/4));
                me->receive_damage("mp",30 + random(11));
                me->start_busy(3);
                message_vision(HIY"\n$N身邊凝聚一股淡淡霧氣，然後被$N的驅體給吸收了。\n"NOR,me);
                return 1;
        }
        if( arg=="shield" )
        {
                if( me->query_temp("skill/cloudshield") > 0 )
                {
                        if( me->is_ghost() )
                                return notify_fail("\n你現在可是鬼呀！怎麼使用『二重凝雲氣』來護身？\n");
                        if( me->is_fighting() )
                                return notify_fail("\n戰鬥中你沒那種時間運氣的啦。\n");
                        if( me->is_busy() )
                                return notify_fail("\n先等你做完手邊的事再說吧。\n");
                        if( me->query_skill_mapped("force")=="cloudforce" )
                                return notify_fail("\n你仍在修煉 (或使用) 凝雲心法之中喔。\n"); 
                        if( me->query_temp("skill/cloudshield") > 1 )
                                return notify_fail("\n你以為你多強啊，想要運行第三重『凝雲氣』？\n");       
                        if( me->query("ap") < 550 )
                                return notify_fail("\n你的內力不足以使用第二重的『凝雲氣』。\n");
                        if( me->query_skill("cloudforce") < 80 )
                                return notify_fail("\n你的凝雲心法根基還不足以使用第二重『凝雲氣』。\n");
                        if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3) &&
                            me->is_busy() )
                                return notify_fail("\n先別那麼急，等一下會死啊？。\n");
                        sk = (int)me->query_skill("cloudforce");
                        ap = (int)me->query("ap");
                        if ( sk > 80 ) sk = 80 + ((sk-80)*2);
                        if ( ap > 1000 ) ap = 1000 + ((ap-1000)/8);
                        shield = (sk/10) + (ap/80);
                        if ( shield > 30 ) shield = 30 + ((shield-30)/3);
                        me->add_temp("apply/armor",shield);
                        me->add_temp("apply/shield",shield/2);
                        me->receive_damage("ap",400+(shield*4));
                        me->start_busy(4);
                        me->add_temp("skill/cloudshield", 1);
                        me->add_temp("skill/shieldarmor",shield);
                        message_vision(HIC"\n$N四周凝聚了一股半透明的氣牆，是十分深厚的護身氣勁。\n"NOR,me);
                        return 1;
                }
                if( me->is_ghost() )
                        return notify_fail("\n你現在可是鬼呀！怎麼使用『凝雲氣』來護身？\n");
                if( me->is_fighting() )
                        return notify_fail("\n戰鬥中你沒那種時間運氣的啦。\n");
                if( me->is_busy() )
                        return notify_fail("\n先等你做完手邊的事再說吧。\n");
                if( me->query_skill_mapped("force")=="cloudforce" )
                        return notify_fail("\n你仍在修煉 (或使用) 凝雲心法之中喔。\n");        
                if( me->query("ap") < 50 )
                        return notify_fail("\n你的內力不足以使用『凝雲氣』喔。\n");
                if( me->query_skill("cloudforce") < 25 )
                        return notify_fail("\n你的凝雲心法根基還不足以使用『凝雲氣』。\n");
                if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3) && 
                    me->is_busy() )
                        return notify_fail("\n先別那麼急，等一下會死啊？\n");
                sk = (int)me->query_skill("cloudforce");
                ap = (int)me->query("ap");
                if ( sk > 60 ) sk = 60 + ((sk-60)/2);
                if ( ap > 500 ) ap = 500 + ((ap-500)/10);
                shield = (sk/12) + (ap/90);
                if ( shield > 13 ) shield = 13 + ((shield-13)/2);
                me->add_temp("apply/armor",shield);
                me->add_temp("apply/shield",shield/2);
                me->receive_damage("ap",30+random(11));
                me->start_busy(3);
                me->add_temp("skill/cloudshield", 1);
                me->add_temp("skill/shieldarmor",shield);
                message_vision(HIC"\n$N身上發出了一道內勁環繞著$N的四周。\n"NOR,me);
                return 1;
        }
        if( arg=="shield_off" )
        {
		if( !me->query_temp("skill/cloudshield") )
			return notify_fail("\n你並沒有使用『凝雲氣』護身。\n");
                downsh=(int)me->query_temp("skill/shieldarmor");
		message_vision(HIB"\n$N身旁的氣慢慢的消散掉了。\n"NOR,me);
		me->delete_temp("skill/cloudshield");
                me->delete_temp("skill/shieldarmor");
                me->delete_temp("skill/shieldtime");
		me->start_busy(2);
		me->add_temp("apply/armor",-(downsh));
                me->add_temp("apply/shield",-(downsh/2));
		return 1;
	}
        if( me->is_ghost() )
                return notify_fail("\n你現在可是鬼呀！怎麼運功\啊？\n");
        if( me->is_fighting() )
                return notify_fail("\n真敬佩你的勇氣，不怕練功\練到岔氣的怪物。\n");
        if( me->is_busy() )
                return notify_fail("\n先等你做完手邊的事再說吧。\n");
        if( me->query_temp("skill/cloudshield") )
                return notify_fail("\n你沒有辦法一面維持『凝雲氣』一面修練凝雲心法。\n");
        if( me->query_skill_mapped("force")=="cloudforce" )
                return notify_fail("\n你仍在修煉 (或使用) 凝雲心法之中喔。\n");
        if( me->query("hp") < 30 || me->query("ap") < 40 || me->query("mp") < 20 )
                return notify_fail("\n你真愛說笑，這種身體狀況怎麼練功\啊。\n");
        if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3))
          return notify_fail("\n你練功\的動作還沒完成。\n");
        message_vision(HIB"\n$N盤起雙腳，靜坐於地，全身環繞霧氣，開始修練凝雲心法。\n"NOR,me);
        me->map_skill("force","cloudforce");
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2+random(2));
        me->receive_damage("mp", 1+random(2));
        me->set_temp("is_busy/cloudforce","你正在修練凝雲心法，無法移動。");
        me->start_busy(4);
        return 1;
}
void delay(object me)
{
        int sk_level,lv,i,shdown;
        lv = me->query("level");
        i = me->query_int();
        if( !me ) return;
        if( me->query_temp("skill/cloudshield") )
        {
                shdown = (int)me->query_temp("skill/shieldarmor");
                if( me->query("ap") < 20 )
                {
                        message_vision(CYN"\n$N的身體狀況太差, 護身氣勁慢慢散掉了。\n"NOR,me);
                        me->delete_temp("skill/cloudshield");
                        me->delete_temp("skill/shieldarmor");
                        me->delete_temp("skill/shieldtime");
                        me->add_temp("apply/armor",-(shdown));
                        me->add_temp("apply/shield",-(shdown/2));
                }
                if( me->query_temp("skill/shieldtime") > 100 )
                {
                        message_vision(HIB"\n$N猛然一沉氣，護身氣勁已經散掉了。\n"NOR,me);
                        me->delete_temp("skill/cloudshield");
                        me->delete_temp("skill/shieldarmor");
                        me->delete_temp("skill/shieldtime");
                        me->add_temp("apply/armor",-(shdown));
                        me->add_temp("apply/shield",-(shdown/2));
                }
                me->add_temp("skill/shieldtime", 1);
                me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3);
        }
        if( me->query_skill_mapped("force")!="cloudforce" ) return;
        if( me->query("ap") < 20 || me->query("hp") < 30 || me->query("mp") < 40 )
        {
                message_vision(CYN"\n$N深吸了一口氣，無力的站起來，無法再將凝雲心法練下去了。\n"NOR,me);
                me->delete_temp("is_busy/cloudforce");
                me->map_skill("force");
                return;
        }
	me->receive_damage("ap",7);
        me->receive_damage("hp",3+random(2));
        me->receive_damage("mp",2+random(2));
        me->improve_skill("force",random((1+random(lv)+random(i))/8) + (lv/15) + (i/10));
        me->improve_skill("cloudforce",random((1+random(lv)+random(i))/9) + (lv/10) + (i/9));
 	me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b;
        b=me->query_skill("cloudforce");
        if( b == 81 && !me->query("skill/cloudforce") )
        {
                tell_object(me, HIY"\n你的凝雲心法衝破大關了！\n"NOR);
                me->add("addition/con", 1);
                tell_object(me, HIC"你的體格上升了！\n"NOR);
                me->set("skill/cloudforce", 1);
        }
        me->save();
}
int improve_limite(object ob)
{
        int a,b;
        b=ob->query_skill("force");
        a=((ob->query("level") + ob->query_int())*2)-9;
        if( ob->query("adv_class")==2 ) a=95;
        else if(a > 80) a=80;
        else if(a >= b) a=b;
        return a; 
}

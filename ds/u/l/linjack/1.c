// 基本的是參考godsword、star-sword，在這註明一下。
// 8/15 2000 by lestia
// 靈修幻劍 
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay_0(object me);
void stop_delay(object me);

mapping *action = ({
        ([
        "action": "$N手拿$w，隨著$w的舞動，劍身合一，直直刺向$N。",
        "damage":                15,
        "dodge" :                10,
        "parry" :                -8,
        "attact_type":  "bio",  // 設定技能的攻擊種類
                                // 種類有 生物(bio) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N使出靈修幻劍中的『幻影靈劍』，只見$N手中的$w忽影忽現，突然的往$n身上刺去。",
        "damage":                10,
        "dodge":                 -5,
        "parry" :                14,
        "attact_type":  "bio",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N將手中的$w，手劃大圓，劍勢霸道，一式『閃靈雷劍』向一道雷電衝向$n。",
        "damage":                17,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bio",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N腳步往後，馬步紮穩，手中$w猶如一條綿蛇，往$n直奔而去。",
        "damage":                13,
        "dodge" :                20,
        "parry" :                -10,
        "attact_type":  "bio",
        "damage_type":  "劍傷",
        ]),

        ([
 "action": "$N步法迷幻，隨著心意擺\動，忽左忽右，$w冷不防的刺向$n。",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bio",
        "damage_type":  "刺傷",
        ]),
});
// 沒評比，攻擊力要討論
int cast_skill(object me,string a, object target, string arg)
{
        int x,damage,i; 
        string msg;
        string *attack = ({
                HIY"一道發出金黃色劍氣的光束飛去刺向$n。\n"NOR,
                HIR"一道發出赤紅色劍氣的光束飛去刺向$n。\n"NOR,
                HIC"一道發出綻藍色劍氣的光束飛去刺向$n。\n"NOR, 
                NOR""YEL"一道發出土黃色劍氣的光束飛去刺向$n。\n"NOR,
		HIG"一道發出亮綠色劍氣的光束飛去刺向$n。\n"NOR,
		HIB"一道發出深藍色劍氣的光束飛去刺向$n。\n"NOR,
		HIM"一道發出淺紫色劍氣的光束飛去刺向$n。\n"NOR,
		HIW"一道發出純白色劍氣的光束飛去刺向$n。\n"NOR,
	});
        string *miss = ({
                HIG"$n"+HIG"身形後飄，避開了這招 \n"NOR,
                HIR"$n"+HIR"騰空而起，輕易的閃開 \n"NOR, 
                HIG"$n"+HIG"將內力運於全身命脈，硬生生的將$N震了開去 \n"NOR, 
                });
                string *hit = ({
                HIR"$n"+HIR"被劍所制，閃躲不及，硬生生的中招。\n"NOR,
                HIR"$n"+HIR"還沒來的及反應，已被$N劍氣所傷。\n"NOR, 
        });
        int p_force = this_player()->query_skill("star-sword")/5,
            w_force = this_player()->qiery_skill("soul-force"),
            b_force = random(this_player()->query_skill("soul_force"))/4,
            spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force ),
            sk = me->query_skill("soul-of-magic-sword"), 
            force = me->query_skill("force"),
            sw = me->query_skill("soul-of-magic-sword"),
            target_armor, me_damage, target_dodge, me_dex, sum_damage, penuma_damage, g,
            myexp=(int)me->query("combat_exp")/5000,
            mylev=(int)me->query_skill("soul-of-magic-sword"),
            mykar=(int)me->query_kar(),
       targetlev,targetkar,targetexp,targeteffkee;
        object weapon, *attack_targets;        
        weapon = me->query_temp("weapon");
        if( arg=="off" )
        {
        	if( me->query_skill_mapped("sword")!="soul-of-magic-sword" )
                        return notify_fail(HIR"你並沒有在用【靈修幻劍】喔！\n"NOR);
                me->map_skill("sword");
                me->reset_action();
                write(HIY"你不繼續使用「靈修幻劍」了！\n"NOR);
                return 1;
        }

        if( me->query("ap") < 30 ) return notify_fail("你的內勁還不能使用靈修幻劍。\n");
        if( !weapon ) return notify_fail("要使出靈修幻劍要先裝備劍喔。\n");
        if( sw < 70 ) return notify_fail("你的靈修幻劍還不夠純熟。\n");
        if( weapon->query("skill_type")!="sword" )return notify_fail("要使出靈修幻劍要先裝備劍喔。\n");
        if( arg == "?" || arg == "help" )
        {
        	tell_object(me,
        	HIR"【靈修幻劍】的功\能有:\n"
        	HIR"\t第一層: 炎匕(fire-dagger)\n"
        	HIR"\t第二層: 寒刃(ice-blade)\n"
        	HIR"\t第三層: 風刀(wind-blade)\n"
        	HIR"\t第四層: 幻戟(dream-lance)\n"
        	HIR"\t第五層: 破天斧(sky-axe)\n"
        	HIR"\t最終層: 八劍滅輪(eight-sword)\n"NOR);
        	return 1;
        }
        if( me->query_skill_mapped("sword") == "star-sword" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("你還在使用靈修幻劍喔！\n");
                if( !me->can_fight(target) ) return me->can_fight(target);
                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me->query_damage() + w_force/4 + sk/3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                if( !arg || arg == "?" )
                {
                	tell_object(me,
                	HIR"【靈修幻劍】的功\能有:\n"
                	HIR"\t第一層: 炎匕(fire-dagger)\n"
                        HIR"\t第二層: 寒刃(ice-blade)\n"
                        HIR"\t第三層: 風刀(wind-blade)\n"
                        HIR"\t第四層: 幻戟(dream-lance)\n"
                        HIR"\t第五層: 破天斧(sky-axe)\n"
                        HIR"\t最終層: 八劍滅輪(eight-sword)\n"NOR);
                        return 1;
                }
                if( me->query_skill_mapped("sword") == "soul-of-magic-sword" )
                {
                	if( !target ) target = offensive_target(me);
                        if( !target ) return notify_fail("你還在使用靈修幻劍喔！\n");
                        if( !me->can_fight(target) ) return me->can_fight(target);
                //沒討論評比，先不改。
                        target_armor = target->query_armor();
                        target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                        me_dex = me->query_dex() * 3;
                        me_damage = me->query_damage() + w_force/4 + sk/3;
                        me_damage = me_damage + random(me_damage/4);
                        sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                        if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                        if( !arg || arg == "?" )
                        {
                        	tell_object(me,
                        	HIR"【靈修幻劍】的功\能有:\n"
                                HIR"\t第一層: 炎匕(fire-dagger)\n"
                                HIR"\t第二層: 寒刃(ice-blade)\n"
                                HIR"\t第三層: 風刀(wind-blade)\n"
                                HIR"\t第四層: 幻戟(dream-lance)\n"
                                HIR"\t第五層: 破天斧(sky-axe)\n"
                                HIR"\t最終層: 八劍滅輪(eight-sword)\n"NOR);
                                return 1;
                        }
                        if( arg == "fire-dagger" )
                        {
                        	if( !me->is_fighting(target) ) me->kill_ob(target);
                        	if( !target->is_fighting(me) ) target->kill_ob(me);
                        	if( me->is_busy() ) return notify_fail("你正在忙！\n");
                        	if( me->query_skill("soul-of-magic-sword") < 30 )
                        	        return notify_fail("你的能力不夠使出炎匕！\n");
                        	message_vision(HIY"\n\t$N將靈氣發揮，運氣將手中之" + weapon->name() + "變化成一把赤紅火熱的匕首。\n\n\t"NOR""YEL"匕首在空中旋繞兩圈，化作一道紅光，往$n的方向射去。\n"NOR, me, target);
                        	if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        	{
                        		target->receive_damage("ap", sum_damage/10, me);
                        		target->receive_damage("hp", sum_damage, me);
                        		target->start_busy(random(3));
                        		message_vision(HIR"$n被赤紅的紅光嚇到，呆立在那，穩穩的吃了一記，鮮血直噴！！"NOR, me, target);
                        		if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                        		me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                        		me->improve_skill("sword", random(me->query_int()/6) + 5 );
                        		me->add_busy(2);
                        		message_vision(HIC"因為$N使用了炎匕，使得$N手中的" + weapon->name() + "掉在地上了！\n"NOR,me);
                        		me->query_temp("weapon")->move(environment(me)); //不掉在地上好像就不像射的吧..:PPP 
                        	}
                        	else
                        	{
                        		message_vision(HIG"$n凝神聚氣，看準了紅光，閃身而過。"NOR, me, target);
                        		target->imporve_skill("dodge", 2);
                        		sum_damage = 0;
                        		message_vision(HIC"因為$N使用了炎匕，使得$N手中的" + weapon->name() + "掉在地上了！\n"NOR,me);
                        		me->query_temp("weapon")->move(environment(me));
                        		me->add_busy(2);
                        	}
                        	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        	message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                        	else message_vision("\n\n", me);
                        	//              COMBAT_D->report_status(target);
                        	me->receive_damage("ap", 28 + sum_damage/40 );
                        	return 1;
               			}
                		if( arg == "ice-blade" )
                		{
                        	if( !me->is_fighting(target) ) me->kill_ob(target);
                        	if( !target->is_fighting(me) ) target->kill_ob(me);
                        	if( me->is_busy() ) return notify_fail("你正在忙！\n");
                        	if( me->query_skill("soul-of-magic-sword") < 50 )
                        	        return notify_fail("你的能力不夠使出寒刃！\n");
                        	message_vision(HIY"\n\t$N將靈氣發揮，運氣將手中之" + weapon->name() + "變化成一把冰寒的的刀刃。\n\n\t"NOR""YEL"一把刀狀的東西慢慢從$N身前浮現突然間劈向$n。\n"NOR, me, target);
                                if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                                {
                                	target->receive_damage("ap", sum_damage/10, me);
                                	target->receive_damage("hp", sum_damage, me);
                                	target->start_busy(random(3));
                                	message_vision(HIC"$n被冰寒的冰氣凍到，渾身發寒，穩穩的吃了一刀，鮮血直噴！！"NOR, me, target);
                                	if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                	me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                                	me->improve_skill("sword", random(me->query_int()/6) + 5 );
                                	me->add_busy(2);
                                }
                                else
                                {
                                	message_vision(HIG"$n凝神聚氣，看準了刀刃，閃身而過。"NOR, me, target);
                			target->imporve_skill("dodge", 2);
                			sum_damage = 0;
                			me->add_busy(2);
                		}
                	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                	message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                	else message_vision("\n\n", me);
//           	   	COMBAT_D->report_status(target);
                	me->receive_damage("ap", 28 + sum_damage/40 );
                        return 1;
                }
              	if( arg == "wind-blade" )
              	{
	                if( !me->is_fighting(target) ) me->kill_ob(target);
        	        if( !target->is_fighting(me) ) target->kill_ob(me);
                	if( me->is_busy() ) return notify_fail("你正在忙！\n");
                	if( me->query_skill("soul-of-magic-sword") < 70 )
                		return notify_fail("你的能力不夠使出風刀！\n");
			message_vision(HIG"\n\t$N將靈氣運轉全身，運用風之力量，將手中之" + weapon->name() + "幻"NOR""GRN"化成一把巨大的的刀刃。\n\n\t"NOR""GRN"$N手中突然出現一把巨刀，往$n斬下。"NOR, me, target);
                	if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                	{
                		target->receive_damage("ap", sum_damage/10, me);
                		target->receive_damage("hp", sum_damage, me);
                		target->start_busy(random(3));
                		message_vision(HIR"$n被一把巨大的刀刃斬傷，渾身發抖，重重的吃了一刀，鮮血直噴！！"NOR, me, target);
                		if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                		me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                		me->improve_skill("sword", random(me->query_int()/6) + 5 );
                		me->add_busy(2);
                	}
                	else
                	{
                		message_vision(HIG"$n凝神聚氣，看準了刀身，閃身而過。"NOR, me, target);
                		target->imporve_skill("dodge", 2);
                		sum_damage = 0;
                		me->add_busy(2);
                	}
        	        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                	else message_vision("\n\n", me);
//      	        COMBAT_D->report_status(target);
	                me->receive_damage("ap", 28 + sum_damage/40 );
             	        return 1;
                }
                if( arg == "dream-spear" )
                {
                	if( !me->is_fighting(target) ) me->kill_ob(target);
                	if( !target->is_fighting(me) ) target->kill_ob(me);
                	message_vision(HIM"$N將手中的" + weapon->name() +"當做一"NOR""MAG"把槍，使出幻影。"NOR, me, target);
                	if( random(target->query_dex()) < random(me->query_dex()*3/2) )
                	{
                	message_vision(HIR"因為$N被幻影所惑，使得$N動彈不得！\n"NOR, target);
                	if( sk < 30 ) target->start_busy(1+random(2));
                	if( sk > 30 && sk < 60 ) target->start_busy(2+random(2));
	        	if( sk > 60 && sk < 90 ) target->start_busy(3+random(2));
        		if( sk >= 90 )
        		{
		                target->receive_damage("hp", me->query_damage()/3, me);
        		        target->start_busy(3+random(2));
                		message_vision(HIR"因為$N被幻影所惑，因此$N受了點傷！"NOR, target);
                	}
                	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                	message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                	else message_vision("\n", me);
                	COMBAT_D->report_status(target);
                	}
                	else
                	{
	                	message_vision(HIW"但卻被$N輕鬆的閃了開去。\n"NOR,target);
        	        	me->add_busy(random(2));
                	}
                	me->receive_damage("ap", 20 - sk/15);
                	me->add_busy(1); //Luky
                	return 1;
                }
                if( arg == "sky-axe" )
                {
                if( !me->is_fighting(target) ) me->kill_ob(target);
                if( !target->is_fighting(me) ) target->kill_ob(me);
                message_vision(HIC"$N凝神聚氣，將手中" + weapon->name() +"用力一抖，忽見$N手中出現一把鋒利的斧頭。"NOR""CYN"\n\n\t$N用力的往$n頭頂砸下。"NOR, me, target);
                if( random(target->query_dex()) < random(me->query_dex()*3/2) )
                {
                message_vision(HIW"因為$N被幻影所惑，使得$N動彈不得！\n"NOR, target);
                if( sk < 40 ) target->start_busy(1+random(2));
                if( sk > 50 && sk < 70 ) target->start_busy(2+random(2));
                if( sk > 80 && sk < 100 ) target->start_busy(3+random(2));
                if( sk >= 100 )
                {
                target->receive_damage("hp", me->query_damage()/3, me);
                target->start_busy(3+random(2));
                message_vision(HIR"$N被突如其來的巨斧砸重，跌倒在地！"NOR, target);
                }
                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                else message_vision("\n", me);
                COMBAT_D->report_status(target);
                }
                else
                {
                message_vision(HIG"但卻被$N輕鬆的閃了開去。\n"NOR,target);
                me->add_busy(random(2));
                }
                me->receive_damage("ap", 20 - sk/15);
                me->add_busy(1); //Luky
                return 1;
                }
// 以下會發生crash

                if( arg == "eight-sword" )
                {
 	        if( !target ) 
  	        target = offensive_target(me);
  		if(!target
  		|| !target->is_character()
  		|| !me->is_fighting(target) )
  		return notify_fail("八劍滅輪，只能對戰鬥對手施用。\n");
  	        targetexp=(int)target->query("combat_exp")/5000;
  		targetlev=(int)target->query_skill("parry");
  		targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
  		targeteffkee=(int)target->query("eff_kee"); 
  		targetkar=(int)target->query_kar();
  
	        if(me->query_skill("soul-of-magic-sword",1)<150)
  		return notify_fail("你還不會使用八劍滅輪﹗\n");

	        if(me->query_skill("soul-force",1)<100)
  		return notify_fail("你還不會使用八劍滅輪﹗\n"); 

  		if(me->query_skill("dream-soul-step",1)<110) 
  		return notify_fail("你還不會使用八劍滅輪﹗\n"); 

  		if( me->query("max_ap") < 1500 || me->query("ap")<400 )
  		return notify_fail("你的內勁不足。\n");

		msg=HIR"$N"HIR"運起靈氣法，將內勁催至頂峰，"NOR""RED"運於全身之間，$N"HIR"頭上出現一巨大劍輪，"NOR""RED"頓時突然往$n身上飛去"NOR;
  
  		message_vision(msg, me, target);
  
  		me->add("ap", -300);
 
  		x=8; 
  		i=0;
  		damage=(int)me->query_skill("soul-of-magic-sword",1);

  		while(x < 9)
  		{
//  			if(target->query_temp("pk_die"))break;
                        msg = attack[random(sizeof(attack))];
 if( random(mylev) >   (targetlev))
                        {
                        	msg += attack[random(sizeof(damage))];
                        	target->receive_wound("hp", damage/2); 
                        	target->receive_damage("hp",damage+random(damage));
                        	message_vision(msg+"\n", me, target);
                        	COMBAT_D->report_status(target);
                        	i=1;
                        } 
                        else
                        {
                        	msg +=miss[random(sizeof(miss))];
                        	message_vision(msg+"\n",me,target);        
                        }
                        x++;
		} 	
  		me->start_busy(2);  
  		return 1;
}  

}
}
}
void delay_0(object me)
{
        object me_weapon;
        int sk = me->query_skill("soul-of-magic-sword");
        if( !me ) return;
        me_weapon=me->query_temp( "weapon" );
        if( !me_weapon || me_weapon->query("skill_type") != "sword" )
        {
        me->map_skill("sword");
        me->reset_action();
        return;
        }
        if( me->query_skill_mapped("sword")!="soul-of-magic-sword" ) return;
        if( me->query("ap") < 20 )
        {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me, HIR"你的體力不夠繼續使『靈修幻劍』了！\n"NOR);
        return;
        }
        if( me->is_fighting() ) me->receive_damage("ap", 10);
        me->skill_active("soul-of-magic-sword",(: call_other, __FILE__, "delay_0", me :), 6);
}
void stop_delay(object me)
{
        if( !me ) return;
        me->delete_temp("class_wind/penuma-sword");
}

int valid_learn(object me)
{
        return 1;
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}


int improve_limite(object ob)
{
        return 100;
}

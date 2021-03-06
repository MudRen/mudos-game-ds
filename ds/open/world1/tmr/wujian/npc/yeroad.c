#include <ansi.h>

inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N揮拳攻擊$n的$l",
                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "attact_type":  "sou",
                "damage_type":  "抓傷",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一腳",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N提起拳頭往$n的$l捶去",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N對準$n的$l用力揮出一拳",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),

});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void kill_ob(object ob)
{
        object *guard;
        int i;
        if(!ob || ob==this_object()) return;
        ::kill_ob(ob);

                 guard = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(guard);i++) {
                if( !guard[i]->id("_WUJIAN_") ) continue;
                if( guard[i] == this_object() ) continue;
                if( guard[i]->is_killing(ob->id()) ) continue;

                // guard to kill
                guard[i]->kill_ob(ob);
        }
}

int special_attack(object me,object target,int hitchance) {
                int dmg;
                if( is_busy() ) return 0;
                if( query_temp("do_attack") ) return 0;
            // 30%機率發動特攻
            if( random(100) < 70 )
                return 0;

                dmg = query_damage() + random(query_damage());
                dmg = COMBAT_D->Merits_damage(me,target, dmg,"sou");

                if(dmg <1) dmg = 1;
        message_vision(HIY"\n業途靈魔氣化做數百道烈焰沖天，竟是成名絕技【　火　龍　金　魔　體　】！！\n"
                        +HIR"數百條熾熱熱的火蛇纏繞上$n"HIR"，在慘叫聲中化做火人！！("+ dmg + ")\n\n"NOR, me, target);
         target->receive_damage("hp", dmg, this_object());
         target->receive_damage("ap", 1 + dmg/2, this_object());
        return 1;
}


void create()
{
        set_name(HIR "業途靈" NOR,({"yeroad spirit", "yeroad","spirit",  "_WUJIAN_"}));
        set("gender", "男性");
        set("long",@LONG
出身滅境，在數百年前是與鬼王棺、腹中首合稱「三途判」為禍蒼生
的大魔頭，且為不死之身，唯有一頁書為其天敵。業途靈自從於霹靂
劫時期出場後，即與鬼王棺、腹中首、十三邪靈大鬧苦境，造成生靈
塗炭。但三途判的弱點——可被七根吸雷針煉化——被知悉後，被造
世七俠煉化於七星拱月臺，只能藉由一口真氣借體於僥倖逃出的鬼王
棺身上。這段時間中，並未有太大作為。
LONG
        );

        set("level", 50);
        set("age", 400);
         set("race","tiger");
        set("title", CYN "三途判" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
            set("max_hp",15000);
        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
                carry_object(__DIR__"obj/liyuan-claw")->wield();
                if(random(3)==1) carry_object(__DIR__"obj/mercury-lode");

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
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

         ob->add("popularity", 2);
         tell_object(ob,HIG "(你獲得 2 點聲望。)\n" NOR);

        ::die();

        return;
}



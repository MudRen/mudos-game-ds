#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "$N一招「鬼引空心」，陰森恐怖的氣團迅速者攻向$n的$l",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$N對著$n的$l使出「萬劫盡捨」，恐怖絕倫的肅殺之氣，硬是深入皮肉數分",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$N臉上黑氣大盛，竟是「陰陵扣命」的殺招，$n招式已盡，身上的$l不慎中招",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$N身形陡然加速，使出「迷蹤行殺」的暗殺絕技，快捷無倫，忽地一指刺向$n的$l",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n的$l忽地皮肉綻開，竟不知不覺就中了$N的「引歸殺象的」殺招",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
                ([
                "damage_type":  "傷害",
                "action":               "$N揮動$w﹐奮力的劈向$n的$l",
                "parry":                20,
                "attact_type":  "sou",
              ]),

                ([
                "damage_type":  "斲傷",
                "action":               "$N用$w往$n的$l砍去",
                "parry":                20,
                "attact_type":  "sou",
              ]),

                ([
                "damage_type":  "斲傷",
                "action":               "$N揮動$w﹐奮力的劈向$n的$l",
                "parry":                20,
                "attact_type":  "sou",
              ]),
                ([
                "damage_type":  "斲傷",
                "action":               "$N的$w朝著$n的$l劈將過去",
                "parry":                20,
                "attact_type":  "sou",
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


void create()
{
        set_name(HIR "鬼王棺" NOR,({"coffin ghost-king","coffin","king", "_WUJIAN_"}));
        set("gender", "男性");
        set("long",@LONG
鬼王棺為三途判之首、狡突臉、渾沌三棺之一、魔劍道第二殿軍師。
LONG
        );

        set("level", 60);
        set("age", 400);
           set("attack_merits","sou");
        set("title", CYN "三途判" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
        set_temp("apply/damage",200);
        set_temp("apply/armor",300);
        set_temp("apply/shield",300);


        setup();
                carry_object(__DIR__"obj/sadness-pike")->wield();
                carry_object(__DIR__"obj/blood-boots")->wear();
                  carry_object(__DIR__"obj/boton-leggings")->wear();
                carry_object(__DIR__"obj/mercury-lode");
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if(!objectp(who)) return damage;

        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                  if(random(100)<50)
                {
                        this_object()->receive_heal("hp", damage/2);
                        damage = 1;
                        switch(random(4) )
                        {
                        case 0:
                                message_vision(HIY "\n$N"HIY"使出魔門絕技「柔剛並合催形化氣」，$n的攻擊竟起不了了任何效果。\n" NOR,this_object(),who);
                                break;
                        case 2:
                                message_vision( "\n$N"HIB"催起「虛轉輪迴滅」大法，$n"HIB"陷入數世前的輪迴惡夢，短時間無法回神...\n" NOR,this_object(), who);
                              // who->add_busy(2);
                             who->receive_damage("mp", 300 + random(100) );
                             who->receive_damage("ap", 300 + random(100) );
                                break;
                        default:
                                message_vision( "\n$N"NOR"使出"HIC"「飛魔穿雲」"NOR"，轉瞬間就避開這次的攻擊了。\n" NOR,this_object());
                        break;          
                                } // end switch
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

                message("world:world1:vision",
                        HBK "\n\t三途判之首 " HIR"鬼王棺"HBK" 不敵被" +ob->name(1) + HBK"破去真身，只能藉由最後一口真氣僥倖逃出！！\n\n"+NOR, users() );

        ob->add("popularity", 5);
         tell_object(ob,HIG "(你獲得 5 點聲望。)\n" NOR);

        ::die();

        return;
}



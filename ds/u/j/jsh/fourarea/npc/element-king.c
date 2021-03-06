#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "半空中浮現出一朵蓮花，以極快的速度攻向$n的$l",
                "attact_type":  "sou",
                "damage_type":  "撞傷",
        ]),
        ([  "action":       "$n的$l上突然浮現出一個手掌印，深入皮肉數分",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n腳下一個不穩，竟然導致身上的$l撞向路旁的金佛像",
                "attact_type":  "sou",
                "damage_type":  "撞傷",
        ]),
        ([  "action":       "$n忽然慘叫一聲，竟然身上$l衝出一朵蓮花",
                "attact_type":  "sou",
                "damage_type":  "撕裂傷",
        ]),
        ([  "action":       "$n的雙腳傳來「碰碰」兩聲響，竟然在大腿上浮出二個掌印",
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("如來佛祖",({"rulaifo bonze","bonze","rulaifo"}));
        set("gender", "男性");
        set("long",@LONG
一陣耀眼的光芒刺痛你的眼睛，你無法看清楚如來佛的長相。
LONG
        );
        set("level",50);
        set("age",700);
        set("title","宇宙光明體");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
                set_skill("jingang-finger",100);
        //map_skill("unarmed","jingang-finger");
            set("attitude", "aggressive");
                set_temp("fly",1);
                set_temp("apply/damage",100);
                set_temp("apply/armor",100);
        setup();
        set_living_name("buddha-war-jingang");
                set("default_actions", (: call_other, __FILE__, "query_action" :));
                set("actions", (: call_other, __FILE__, "query_action" :));
                set("combat_exp",500000);
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        int val;
                object sw;      // 疾風門的劍

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage=1;
                        if(objectp(who))
                        {
                                switch(who->query("class1") )
                                {
                                case "八極門":
                                        message_vision(HIC "\n$N虛幻般似真若無的雙臂齊出，把$n的攻擊一一格開。\n" NOR,this_object(),who);
                                        break;
                                case "疾風門":
                                        // 有拿劍類的武器..
                                        if(  objectp( sw=who->query_temp("weapon") ) 
                                                && sw->query("skill_type")=="sword" 
                                                && sw->unequip() ) 
                                        {
                                                message_vision(HIW "\n如來佛祖伸出食、中兩指夾住了$N手上的$n" HIW "，$N竟然就此拿捏不住手上的$n！！\n" NOR,who,sw);
                                                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
                                        }
                                        else 
                                                message_vision(HIM "\n$N身體四周浮出數十朵蓮花，使得$n的攻擊無法準確攻擊到$N...\n" NOR,this_object(),who);
                                        break;
                                case "神武教":
                                        // 有發神武真火
                                        //if(who->query_temp("probit/god-fire") )
                                                message_vision(HIB "\n忽然有如寒凍降臨般，$N四周的空氣竟然結成一層冰霜...\n" NOR,this_object(),who);
                                        //else 
                                        //      message_vision(HIC "\n$N虛幻般似真若無的雙臂齊出，把$n的攻擊一一格開。\n" NOR,this_object(),who);
                                        break;
                                default:
                                        message_vision(HIG "\n$N身影忽然憑空消失，一轉眼又站在其他的方位上。\n" NOR,this_object());
                                        break;          
                                }
                        } else {
                                message_vision(HIG "\n$N身影忽然憑空消失，一轉眼又站在其他的方位上。\n" NOR,this_object());
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

        ob->add("popularity",6);
                tell_object(ob,HIG "(你的聲望增加六點了。)" NOR);
        ::die();

        return;
}


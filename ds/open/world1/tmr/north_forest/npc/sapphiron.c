#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "半空中浮現出一朵蓮花，以極快的速度攻向$n的$l",
                "attact_type":  "wit",
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
        set_name( "薩菲隆" ,({"sapphiron dragon","dragon"}));
        set("gender", "男性");
        set("long",@LONG
一陣耀眼的光芒刺痛你的眼睛，你無法看清楚如來佛的長相。
LONG
        );
        set("level", 80);
        set("age",1200);
        set("race","beast");
        set("title", HIW "冰霜巨龍" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("attitude", "aggressive");
        set_temp("fly", 1);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/shield",500);

       setup();
       set("default_actions", (: call_other, __FILE__, "query_action" :));
       set("actions", (: call_other, __FILE__, "query_action" :));
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

                  if(random(100)<50)

                {
                        this_object()->receive_heal("hp",damage/2);
                        damage=1;
                        switch(random(4) )
                        {
                        case 0:
                                message_vision(HIY "\n$N虛幻般似真若無的雙臂齊出，把$n的攻擊一一格開。\n" NOR,this_object(),who);
                                break;
                        case 1:
                                if(  objectp( sw=who->query_temp("weapon") ) && sw->unequip() ) 
                                {
                                        message_vision(HIW "\n如來佛祖伸出食、中兩指夾住了$N手上的$n" HIW "，$N竟然就此拿捏不住手上的$n！！\n" NOR,who,sw);
                                                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
                                                break;
                                }
                                message_vision(HIM "\n$N身體四周浮出數十朵蓮花，使得$n的攻擊無法準確攻擊到$N...\n" NOR,this_object(),who);
                                break;
                        case 2:
                                message_vision(HIB "\n忽然有如寒凍降臨般，$N四周的空氣竟然結成一層冰霜...\n" NOR,who);
                                who->add_busy(3);

                                break;
                        default:
                                message_vision(HIG "\n$N身影忽然憑空消失，一轉眼又站在其他的方位上。\n" NOR,this_object());
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

        ob->add("popularity",5);
          tell_object(ob,HIG "(你的聲望增加五點了。)\n" NOR);

        if(random(100)<70) {
            // 如來佛心，可替死，但是不能save
            new(__DIR__"obj/heart")->move(ob);
            message_vision("$N從如來佛身上取下一顆跳動的如來佛心。\n",ob);
        }


        ::die();

        return;
}


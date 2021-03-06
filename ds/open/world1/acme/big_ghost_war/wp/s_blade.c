/* write by -Acme-
*/

#include <ansi2.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    switch( random(100) ) {
        case 0..10:
            set_name(CYN"陰息刀"NOR,({ "in sea blade" ,"blade" }) );
            set("long", "整把刀四周散發著一股黑氣，存著相當多的怨靈，恐怕不是把好刀。");
            set_weight(7000);
            set("value", random(4000)+4444);
            set("volume",3);
            set("special_attack",4);
            init_blade(55);
            break;
        case 11..30:
            set_name(CYN"絲纏刀"NOR,({ "se sun blade" ,"blade" }) );
            set("long", "一把以絲纏繞於刀柄的刀，能讓敵人陷於混亂。");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",1);
            init_blade(50);
            break;
        case 31..50:
            set_name(CYN"青眼刀"NOR,({ "green eye blade" ,"blade" }) );
            set("long", "刀身上有一隻青眼，青眼不時左右轉動著，似乎有靈性一般。");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",2);
            init_blade(50);
            break;
        case 51..70:
            set_name(CYN"鬼角刀"NOR,({ "ghost blade" ,"blade" }) );
            set("long", "刀柄是一隻大鬼角，還不停的流著鮮血，似乎斬殺過不少人。");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",3);
            init_blade(50);
            break;
        default:
            set_name(CYN"亦無刀"NOR,({ "yi wu blade" ,"blade" }) );
            set("long", "一把刀身紅透透的刀，看似嚐過不少鮮血一般。");
            set_weight(7000);
            set("value", random(4000)+4444);
            set("volume",3);
            init_blade(48);
            break;
    }

    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("material", "iron");
    }

    switch( random(100) ) {
        case 0..19: set("weapon_prop/str",1); break;
        case 20..39: set("weapon_prop/con",1); break;
        case 40..59: set("weapon_prop/int",1); break;
        case 60..79: set("weapon_prop/dex",1); break;
        case 99:
            set("weapon_prop/str", 1);
            set("weapon_prop/con", 1);
            set("weapon_prop/int", 1);
            set("weapon_prop/dex", 1);
            break;
    }

    setup();
}

void attack(object me, object target)
{
    int attack, damage;
    ::attack();

    if( !this_object()->query("special_attack") ) return;
    if( !me || !target ) return;
    if( me->is_busy() || me->query("ap") < 100 ) return;
    if( random(100) < 80 ) return;

    switch( this_object()->query("special_attack") ) {
        case 1:
            message_vision(CYN"$N手中"+this_object()->query("name")+CYN"脫出許\多怨靈，圍繞在$n身邊。\n"NOR,me, target);
            target->start_busy(random(3)+1);
        break;
        case 2:
            message_vision(CYN"$N手中"+this_object()->query("name")+CYN"有靈性一般，青光一閃讓人氣色好了許\多。\n"NOR,me);
            me->receive_heal("hp", 50+random(50));
        break;
        case 3:
            message_vision(CYN"$N手中"+this_object()->query("name")+CYN"衝出一惡靈，直擊$n。"NOR,me, target);
            attack = COMBAT_D->attack_factor(me, "blade")*10/15;
            attack -= COMBAT_D->dodge_factor(target, "dodge")*10/15;
            if( attack > 95 ) attack = 95;
            if( attack < 30 ) attack = 30;
            if( attack > random(100) ) {
                damage = 100+random(120);
                message_vision("結果狠狠擊中$N。\n", target);
                target->receive_damage("hp", damage, me); 
                if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                COMBAT_D->report_status(target);
            } else message_vision("結果被$N閃了過去。\n", target);
        break;
        case 4:
            switch( random(3) ) {
                case 0:
                    message_vision(CYN"$N手中"+this_object()->query("name")+CYN"脫出許\多怨靈，圍繞在$n身邊。\n"NOR,me, target);
                    target->start_busy(random(3)+1);
                    break;
                case 1:
                    message_vision(CYN"$N手中"+this_object()->query("name")+CYN"有靈性一般，青光一閃讓人氣色好了許\多。\n"NOR,me);
                    me->receive_heal("hp", 50+random(50));
                    break;
                case 2:
                    message_vision(CYN"$N手中"+this_object()->query("name")+CYN"衝出一惡靈，直擊$n。"NOR,me, target);
                    attack = COMBAT_D->attack_factor(me, "blade")*10/15;
                    attack -= COMBAT_D->dodge_factor(target, "dodge")*10/15;
                    if( attack > 95 ) attack = 95;
                    if( attack < 30 ) attack = 30;
                    if( attack > random(100) ) {
                        damage = 100+random(120);
                        message_vision("結果狠狠擊中$N。\n", target);
                        target->receive_damage("hp", damage, me); 
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                            tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                       COMBAT_D->report_status(target);
                    } else message_vision("結果被$N閃了過去。\n", target);
                    break;
           }
        break;
    }
    me->receive_damage("ap", 20);
    return;
}

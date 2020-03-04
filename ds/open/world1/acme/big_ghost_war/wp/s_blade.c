/* write by -Acme-
*/

#include <ansi2.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    switch( random(100) ) {
        case 0..10:
            set_name(CYN"�����M"NOR,({ "in sea blade" ,"blade" }) );
            set("long", "���M�|�P���o�ۤ@�Ѷ®�A�s�۬۷�h�����F�A���Ȥ��O��n�M�C");
            set_weight(7000);
            set("value", random(4000)+4444);
            set("volume",3);
            set("special_attack",4);
            init_blade(55);
            break;
        case 11..30:
            set_name(CYN"����M"NOR,({ "se sun blade" ,"blade" }) );
            set("long", "�@��H����¶��M�`���M�A�����ĤH����V�áC");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",1);
            init_blade(50);
            break;
        case 31..50:
            set_name(CYN"�C���M"NOR,({ "green eye blade" ,"blade" }) );
            set("long", "�M���W���@���C���A�C�����ɥ��k��ʵۡA���G���F�ʤ@��C");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",2);
            init_blade(50);
            break;
        case 51..70:
            set_name(CYN"�����M"NOR,({ "ghost blade" ,"blade" }) );
            set("long", "�M�`�O�@���j�����A�٤������y���A��A���G�ٱ��L���֤H�C");
            set_weight(5000);
            set("value", random(4000)+2000);
            set("volume",3);
            set("special_attack",3);
            init_blade(50);
            break;
        default:
            set_name(CYN"��L�M"NOR,({ "yi wu blade" ,"blade" }) );
            set("long", "�@��M�����z�z���M�A�ݦ��|�L�����A��@��C");
            set_weight(7000);
            set("value", random(4000)+4444);
            set("volume",3);
            init_blade(48);
            break;
    }

    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
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
            message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"��X�\\�h���F�A��¶�b$n����C\n"NOR,me, target);
            target->start_busy(random(3)+1);
        break;
        case 2:
            message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"���F�ʤ@��A�C���@�{���H���n�F�\\�h�C\n"NOR,me);
            me->receive_heal("hp", 50+random(50));
        break;
        case 3:
            message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"�ĥX�@�c�F�A����$n�C"NOR,me, target);
            attack = COMBAT_D->attack_factor(me, "blade")*10/15;
            attack -= COMBAT_D->dodge_factor(target, "dodge")*10/15;
            if( attack > 95 ) attack = 95;
            if( attack < 30 ) attack = 30;
            if( attack > random(100) ) {
                damage = 100+random(120);
                message_vision("���G��������$N�C\n", target);
                target->receive_damage("hp", damage, me); 
                if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                COMBAT_D->report_status(target);
            } else message_vision("���G�Q$N�{�F�L�h�C\n", target);
        break;
        case 4:
            switch( random(3) ) {
                case 0:
                    message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"��X�\\�h���F�A��¶�b$n����C\n"NOR,me, target);
                    target->start_busy(random(3)+1);
                    break;
                case 1:
                    message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"���F�ʤ@��A�C���@�{���H���n�F�\\�h�C\n"NOR,me);
                    me->receive_heal("hp", 50+random(50));
                    break;
                case 2:
                    message_vision(CYN"$N�⤤"+this_object()->query("name")+CYN"�ĥX�@�c�F�A����$n�C"NOR,me, target);
                    attack = COMBAT_D->attack_factor(me, "blade")*10/15;
                    attack -= COMBAT_D->dodge_factor(target, "dodge")*10/15;
                    if( attack > 95 ) attack = 95;
                    if( attack < 30 ) attack = 30;
                    if( attack > random(100) ) {
                        damage = 100+random(120);
                        message_vision("���G��������$N�C\n", target);
                        target->receive_damage("hp", damage, me); 
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                            tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                       COMBAT_D->report_status(target);
                    } else message_vision("���G�Q$N�{�F�L�h�C\n", target);
                    break;
           }
        break;
    }
    me->receive_damage("ap", 20);
    return;
}

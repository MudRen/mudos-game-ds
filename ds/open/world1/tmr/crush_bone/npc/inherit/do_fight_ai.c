#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // �ɦ�
void do_fight_help();                   // �D��

string file_path = "/open/world1/tmr/crush_bone/npc/";         // �D����npc��m
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_commander.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_herald.c",
                      "orc_envoy.c",
//                      "orc_emperor.c"
                   });

// �b�~�H�S��
void do_fight_issue()
{
        int dmg;
        object me, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;
        target = me->select_opponent();
        if( !target ) return;
    if( environment(target) != environment(me) ) return;

        switch(random(4)) {
                case 0:
                        message_vision("$N�g�ʤj�o���$n�ϥX"HIR"�|���r��"NOR"�A�ۤW�e�ӴN�O�@�}�å��I�I\n"NOR, me, target);
                        me->attack();
                        me->attack();
                        me->attack();
                break;
                case 1:
                        message_vision("$N���$n���}��B�ϥX"HIG"�_��"NOR"�A$n�P��@�}�@�h�A��ʦ��Ǥ��K�I\n"NOR, me, target);
                        target->start_busy(1);
                break;

                case 2:
                    // emperor �|�ή��߳N
                    if( !me->id("_ORC_EMPEROR_") ) {
                        message_vision("$N���������A�����C���m�ըϥX"HIC"�ۭ���"NOR"�A$n�@�ɤ��������D������I�o���ê��۪k�I\n"NOR, me, target);
                        dmg = me->query_damage() - target->query_shield();
                        if(dmg<1) dmg= 10;
                        dmg = COMBAT_D->Merits_damage(me, target, dmg, "bar");
                        target->receive_damage("hp", dmg, me);
                        COMBAT_D->report_status(target);
                    } else {
                        message_vision(HIM"$N����x�۵����A�L�̰�ᦳ��A���⩹�e�@�����V$n�A$n�߸̶}�lı�o�u���ߡv�C\n"NOR, me, target);
                        target->apply_condition("fear", target->query_condition("fear") + 3 + random(3) );
                        target->start_busy(1);
                    }

                break;
       default:
                        message_vision("$N���������A�����C���m�ըϥX"HIC"�ۭ���"NOR"�A$n�@�ɤ��������D������I�o���ê��۪k�I\n"NOR, me, target);
                        target->receive_damage("hp", me->query_damage()/3 + random(me->query_damage()/3), me);
                COMBAT_D->report_status(target);
                break;
        }

}

void do_fight_heal()
{
    object me, hurter, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

        target = me->select_opponent();
        if( !target ) return;

    // �ĤH���ĤH(���ӬO�ۤw�H)
        hurter = target->select_opponent();

    if( !hurter || !objectp(hurter) ) {        
        do_fight_issue();                     // �p�G�S�����n�ɦ媺�H�h�ۤw�ίS�\
        return;
    }

    if( hurter->query("hp") > hurter->query("max_hp")*80/100 ) {
                if( target->query("ap") < target->query("max_ap")*70/100) {
                    message_vision(HIW"$N"HIW"��X���F�_�z���k�N�A����$n"HIW"�Q"HIM"������~"HIW"�]���...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
                if( target->query("mp") < target->query("max_mp")*70/100) {
                    message_vision(HIW"$N"HIW"��X���F�G�k���k�N�A����$n"HIW"�Q"HIR"������~"HIW"�]���...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
        do_fight_issue();                     // �p�G��q�٨����h�ۤw�ίS�\
        return;
    }

    message_vision(HIW"$N"HIW"�L�̰�ᦳ��A����$n"HIW"�|�P�򴲥X�զ���~...\n"NOR, me, hurter);
    hurter->receive_heal("hp", 500 );
}

void do_fight_help()
{
    int i;
    string file;
    object *mob_list;
        object me;

        me = this_object();

        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

    switch( random(100) ) {
        case 0..40: do_fight_issue(); return;
        case 41..60: break;
        default: return;
    }

    file = file_path + mob_file[random(sizeof(mob_file))];

    if( sizeof(mob_list = children(file)) ) {
        for(i=0; i<sizeof(mob_list); i++) {
            if( !environment(mob_list[i]) ) {
                destruct(mob_list[i]);
                continue;
            }

            if( mob_list[i]->is_busy() || mob_list[i]->is_fighting() ) continue;

            // �P�s��MOB���]���]�w set("vendetta_mark", "xxx"); �����A�o��MOB���L�ӫ�|�۰ʧ���
            if( mob_list[i]->move(environment(me)) ) {
                message_vision(HIR"$N"HIR"�o�X��զӼR�q���g�s�n�A�ިӪ���$n�C\n"NOR, me, mob_list[i]);
                return;
            }

            do_fight_issue();               // �ϴ��̵L�k���L�ӫh�ۤw�ίS�\
            return;
        }
    } else do_fight_issue();                     // �䤣��H�����A�ۤw�ίS�\
}


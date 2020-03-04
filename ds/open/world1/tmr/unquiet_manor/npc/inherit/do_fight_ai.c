#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // �ɦ�
void do_fight_help();                   // �D��

string file_path = "/open/world1/tmr/unquiet_manor/npc/";         // �D����npc��m
string *mob_file = ({ "skeleton.c",
                      "evil.c",
                      "evil2.c",
                      "demon.c",
                      "general.c",
                      "solider.c",
                   });

// �S��
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

                if( random(100) < 50) {
                        // �s��
                        message_vision(HIR"$N"HIR"���$n"HIR"�R�X�f©��A�M�ۮ�մۤW�e�ӴN�O�@�}�å��I�I\n"NOR, me, target);
                        me->attack();
                        me->attack();
                        me->attack();
                } else {
                        message_vision(HIM"$N"HIM"�q�L�̦R�g�X�ƤQ���޵��A�������N�I�J$n"HIM"��Ŧ���Ƥ����I�I\n"NOR, me, target);
                        dmg = this_object()->query_damage() - target->query_shield();
                        if(dmg<1) dmg = 10;
                        dmg = COMBAT_D->Merits_damage(me, target, dmg, "wit");
                        target->receive_damage("hp", dmg, this_object());
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
                    message_vision(HIW"$N"HIW"��X�t���N�A����$n"HIW"���W�������K�K�³ª�����...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
                if( target->query("mp") < target->query("max_mp")*70/100) {
                    message_vision(HIW"$N"HIW"��X�t�v�y�S�A$n"HIW"���ո̥R��۴o�H���y�s�n...\n"NOR, me, target);
                        target->receive_damage("mp", me->query_damage()/3 + random(me->query_damage()/3) ,me);
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
    object *mob_list,*obs;
    object me,target;

        me = this_object();
        obs = all_inventory(environment(me));
        target = me->select_opponent();
        if( !target ) return;
        
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;
            if( sizeof(obs) < (target->query_bar() + 15) ) return; 

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
            if( mob_list[i]->move(environment(me)) ) {
                message_vision(HIR"$N"HIR"��ۤ����B���X���I�ϡA�ި�$n�e�������C\n"NOR, me, mob_list[i]);
                return;
            }
            do_fight_issue();               // �ϴ��̵L�k���L�ӫh�ۤw�ίS�\
            return;
        }
    } else do_fight_issue();                     // �䤣��H�����A�ۤw�ίS�\
}

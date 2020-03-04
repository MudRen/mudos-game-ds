#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // �ɦ�
void do_fight_help();                   // �D��

string file_path = "/open/world1/tmr/blood_field/npc/";         // �D����npc��m
string *mob_file = ({ "fetish.c",
                      "cat.c",
                      "hulks.c",
                      "wendigo.c",
                      "fetish_wizard.c",
                      "wild_toast.c",
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
			message_vision(HIR"$N"HIR"���$n"HIR"�q�s�A���۬�����e�X�B�I�I\n"NOR, me, target);
			me->attack();
			me->attack();
			me->attack();
		} else {
			message_vision(HIG"$N"HIG"�u�ܡv���@�n�A�i�L�R�X�@�D�j�l����ۡA�������W$n"HIG"���ݫe�n�`�I�I\n"NOR, me, target);
                          dmg = this_object()->query_damage() - target->query_armor();
			if(dmg<1) dmg = 10;
			dmg = COMBAT_D->Merits_damage(me, target, dmg, "bio");
			target->receive_damage("hp", dmg, this_object());
		}
}

void do_fight_heal()
{
	int dmg;
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
      	dmg = me->query_damage()/3 + random(me->query_damage()/3);
                if( target->query("ap") < target->query("max_ap")*70/100) {
                    message_vision(HIG"$N"HIG"��X��ڳN�A$n"HIG"�����}�Q�a�W�_�X���ʤj��ں�����C\n"NOR, me, target);
                        target->receive_damage("ap",  dmg ,me);
                        target->start_busy(1);
                        return;
                }
                if( target->query("mp") < target->query("max_mp")*70/100) {
                    message_vision(HIM"$N"HIM"��X�����N�A�@�ѱj�P���Į�q$n"HIM"����֦�ު��p�F�i�h...\n"NOR, me, target);
					target->receive_damage("mp", dmg ,me);
					 return;
                }
        do_fight_issue();                     // �p�G��q�٨����h�ۤw�ίS�\
        return;
    }

    message_vision(HIW"$N"HIW"�I�i�^�K�N�A�b$n"HIW"���������X�I�I���~...\n"NOR, me, hurter);
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
        if( sizeof(obs) < (target->query_bio() + 15) ) return; 

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
                message_vision(HIR"$N"HIR"�o�X��ժ��y�s�n�A�ި�$n"HIR"�e�������C\n"NOR, me, mob_list[i]);
                return;
            }
            do_fight_issue();               // �ϴ��̵L�k���L�ӫh�ۤw�ίS�\
            return;
        }
    } else do_fight_issue();                     // �䤣��H�����A�ۤw�ίS�\
}


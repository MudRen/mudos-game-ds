// �p�ӤE��(buddha-skill) �s����
// -Tmr 2006/10/18 
        
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({

        ([
        "action": "$N���$w"NOR"�A�ϥX"HIW"�u����E�{�v"NOR"�A�@�w�������A�N�R�X�ƤQ�ӧ��Y�v����$n��$l�r�M���h",
        "damage":                25,
        "attact_type":  "sou",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(sou) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "ݴ��",
        ]),

        ([
        "action": "$N���W��y�g�ۡA�ϥX"HIW"�u������O�v�A"NOR"$w"NOR"���o�X���H����աA���۴�$n��$l�r�M�V�h",
        "damage":                25,
        "attact_type":  "sou",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(sou) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "����",
        ]),
                
        ([
        "action": "$N�j�ܤ@�n�ϥX"HIW"�u��ʤs�e�v"NOR"�A�|�g���Ů�n�ɾ����_�ӡA$N�@�����X�A�S�p�U�b�ˡA�U���i�צ��a��$n��$l���h",
        "damage":                35,
        "attact_type":  "sou",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(sou) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "����",
        ]),
                
        ([
        "action": "$N�����D�W�b�šA�ϥX"HIW"�u��ݭ{�šv"NOR"�A���褣����B�ǨӤ@�}��"NOR"�A$N��򴤦�$w"NOR"�A��ոU�d�a��$n�����F�\\�V�h",
        "damage":                25,
        "attact_type":  "sou",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(sou) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "����",
        ]),
                
                

});

void delay(object me,int cost);

void improve_skill(object me) {
    me->improve_skill("buddha-skill",1 + random(me->query_int()/2));
    me->improve_skill("staff",1 + random(me->query_int()/2));
}

/* �Z���l�� */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); 
}

/* �P�_�O�_�ݭn�ܶˮ`�Ʀr */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

/* �P�_�O�_�٥��޵o�԰� */
void check_combat(object me, object target) {
        if( !objectp(me) ) return;
        if( !objectp(target) ) return;
      if(!me->is_fighting(target)) me->kill_ob(target);
      if(!target->is_fighting(me)) target->kill_ob(me);
}

int get_tiger_damage(object me, object target)
{
      int damage;
    damage = me->query_skill("buddha-skill") + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);
      if( me->query_temp("buddha-body")) damage +=  damage/2;
    return COMBAT_D->Merits_damage(me, target, damage, "sou");
}


/* ����� �S�� */
void do_tiger_attack(object me, object target) {

    int damage, target_d,sk;
    string msg;

    if( userp(me) && userp(target) ) me->start_busy(2);
    else me->start_busy(1);

    me->receive_daemage("ap", 50);
    
    msg = HIM "$N�k�����x�a���_������L�A���P�ϩ��ۤư_�t����R���[����O�A���_�L�ۡI�I\n" NOR;
    msg += HIW "$N�ۤƦ��p�ӧάۡA�r���@��Ѻ��z��"HIG"�[���k��"HIW"�A�����p���է�V$n�I�I\n" NOR;
    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "�i�O�o�@���o�O�n�z�L�O�A�L�k��$n" HIW "�y������ˮ`...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill("buddha-skill");
    if( sk + random(sk/2) > random(target_d) ) {
        target->add_busy(1+random(2));
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"�Q���ۡu����ѡv���������ݤf�A�����p�D�q���T�I" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // �Z���l��
        show_damage(me, target, damage);        // ��ܶˮ`�Ʀr
        message_vision("\n", me);
        

        COMBAT_D->report_status(target);
                improve_skill(me);
    } else {
        msg += CYN"$n" CYN "���M�Q���������F�A���èS���y�����㪺�ˮ`.....\n" NOR;
        message_vision(msg, me, target);
    }
}

/* �s���������O */
int get_continue_attack_damage(object me, object target) {
    int damage;
    damage = (me->query_skill("buddha-skill") + me->query_damage())/3;
    damage -= target->query_armor()/2 - random(target->query_armor()/2);
    if(damage < 1 ) damage = 1;
    return COMBAT_D->Merits_damage(me,target,damage,"sou");
}



/* ������� */
void do_continue_attack(object me, object target)
{
      int sk, attack_times, a, target_d, damage;
    mapping type;
    string msg;

    sk =  me->query_skill("buddha-skill");
    if( sk < 20) attack_times = 1;
    else    if( sk < 40) attack_times = 1 + random(2);
    else    if( sk < 60) attack_times = 2 + random(2);
    else    if( sk < 80) attack_times = 2 + random(3);
    else    attack_times = 3 + random(3);

    me->receive_damage("ap",attack_times*8);

    if(userp(me) && userp(target)) me->start_busy(2);
    else me->start_busy(1);

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    for( a = 0; a < attack_times; a++ )
    {
        if ( a > 0) msg = HIW"$N���W���~�|�g�A$n"HIW"��o���⤣�ΡA�S�X���j�������I\n"NOR;
        else msg ="";
        type = action[ random(sizeof(action)-1) ];
        msg += "$N�֯e��F�@���N������$n���W�n�`���h�C";

        damage = get_continue_attack_damage(me, target);

        if( damage < 1 ) damage = 1 + random(5);

        if( sk/2+random(sk) > random(target_d)  )       //�s�����������R���v
        {
            msg += RED"���G�y��$n"RED"�@�B���ˡI�I"NOR;
            message_vision(msg, me, target);

            damage_weapon(me);          // �Z���l��

            target->receive_damage("hp",damage,me);
            show_damage(me, target, damage);
            message_vision("\n", me);
            improve_skill(me);
        }
        else        {
            msg += "�i�O�Q$n���{�F�}�h�C\n";
            message_vision(msg, me, target);
        }
    }

    COMBAT_D->report_status(target);
}

/* �ĤG����exert �N�O�I�i�S�� */
int do_exert(object me, object target) {
    int sk;

    if( !target ) target = offensive_target(me);
    if( !target)
        return notify_fail("�A�w�g�b�ϥΡu�p�ӤE���v�F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�A�չϧ������ĤH�w�g���b�F�C\n");

    //�����ʪ��n�S�O�`�N�n�[�U�����.
    if(!me->can_fight(target)) return 0;
    if(target->is_corpse()) return notify_fail("�ݲM���A���v�g���F�C\n");

    sk = me->query_skill("buddha-skill");
    if( sk > 59 && random(sk) > random(150) ) {
        do_tiger_attack(me, target);    // 5. �����
    } else {
        do_continue_attack(me, target); // 6. �������
    }

    check_combat(me, target);
    
    return 1;
}

int exert(object me, object target, string arg)
{
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("staff")!="buddha-skill")
                        return notify_fail("�A�èS���ϥΦp�ӤE��\n");
                me->map_skill("staff");
                me->reset_action();
                write("�ޯ�[�p�ӤE��]�w�����C\n");
                return 1;
        }
        if(!weapon) return notify_fail("�ϥΦp�ӤE�������⤤�n���ڧ��C\n");
        if(weapon->query("skill_type")!="staff") return notify_fail("�ϥΦp�ӤE�������⤤�n���ڧ��C\n");
            //�Ĥ@��exert --> �I�i�S��
                if(me->query("ap")<10 || me->query("hp")<10 )
                        return notify_fail("�A�����骬�p�L�k�ϥΦp�ӤE���C\n");

            //�ĤG��exert --> �I�i�S��
        if(me->query_skill_mapped("staff")=="buddha-skill")
               return do_exert(me, target);        

        if(!me->skill_active( "buddha-skill",(: call_other, __FILE__, "delay", me ,6:), 10))
          return notify_fail("�A�����۰ʧ@�٨S�����C\n");
        me->map_skill("staff", "buddha-skill");
        me->reset_action();
         message_vision( "$N�f�Ŧ򸹡A���o�X���t���Y����աA�}�l�I�i�y�p�ӤE���z�C\n",me);
        me->receive_damage("ap",5);
        me->start_busy(1);
  
      //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        return 1;
}

void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");

        if(!weapon)   {
                me->map_skill("staff");
                me->reset_action();
                return;
        }
        if(weapon->query("skill_type")!="staff")
        {
                me->map_skill("staff");
                me->reset_action();
                return;
        }
        if(me->query_skill_mapped("staff")!="buddha-skill")
        {
         return;
        }
            if(me->query("ap")<20)
        {
                me->map_skill("staff");
                me->reset_action();
                  message_vision("$N����O�����L�k�~��ϥΦp�ӤE��, �u�n��Τ@��ۦ��C\n"NOR,me);
                return ;
   
             }
    if( me->is_fighting() )
        me->receive_damage("ap",5); //luky
     me->skill_active( "buddha-skill",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }



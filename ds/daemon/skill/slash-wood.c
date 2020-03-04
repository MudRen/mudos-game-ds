#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
                       ([
                            "action": "$N�a���^��, ����ꥩ�����_$w��$n�ۼA�ӥh!",
                            "damage":                22,
                            "dodge" :                 5,
                            "parry" :                -5,
                            "attack":                -5,
                            "attact_type":  "bar",	// �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N���R$w, �_���V$n�s�o�T��, ����$n���ۮ�פ���,
                            $N��M��$n�������A�U�h!!",
                            "damage":    10,
                            "dodge" :   -10,
                            "attack":    10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N�@�D, �⤤$w�w��������$n�Y���d�h!",
                            "damage": 18,
                            "attack": -5,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�����$w, ��$n�o�X�S�֤S���S�Ǫ��@��!",
                            "damage": 11,
                            "dodge" : -5,
                            "parry" : -5,
                            "attack": 15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N�@���$w, �V$w��A�L�h, ��M���Τ@��, $N�N$w����,
                            ��$n�g���L�h, �k�p�Q�r!!",
                            "damage":  27,
                            "parry":   -5,
                            "attack":  -5,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,sk,ax,b,d,e,da,bd,force,skill,num,hit,dodge,eny;
    string msg,aa,name;
    object weapon,*enemy;
    mapping type;
    weapon=me->query_temp("weapon");
    da = me->query_damage();
    sk = me->query_skill("slash-wood");
    ax = me->query_skill("axe");
    bd = me->query_skill("blade");
    force = me->query_skill("force");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood" )
            return notify_fail(HIB"�z�{�b�èS���b�ϥ�"HIC"�}��N"NOR"��I\n"NOR);
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        write(HIY"�A����ϥ�"CYN"�}��N"NOR"�F�C\n"NOR);
        return 1;
    }
    if(!weapon)
        return notify_fail(CYN"�}��N"YEL"�����n�t�X�M�l�Ω��Y�@�_�ϥΡC\n"NOR);
    if(weapon->query("skill_type")!="blade" && weapon->query("skill_type")!="axe")
        return notify_fail(CYN"�}��N"YEL"�����n�t�X�M�l�Ω��Y�@�_�ϥΡC\n"NOR);
    name = weapon->query("name");
    if(weapon->query("skill_type")=="blade") skill = sk + bd;
    if(weapon->query("skill_type")=="axe") skill = sk + ax;
    if(arg=="cross-slash")
    {
        if(!me->is_fighting())
            return notify_fail(HIW"\n�z�����b�԰����~��ϥγo���S�ޡC\n"NOR);
        if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
            return notify_fail(HIB"�z�{�b�èS���b�ϥ�"HIC"�}��N"NOR"��I\n"NOR);
        if(me->query_str() < 30 || force < 40 || sk < 40 )
            return notify_fail(HIW"\n�z����O�٤����H�ϥX�o���S�ޡC\n"NOR);
        if(me->query("ap") < 200)
            return notify_fail(HIW"\n�z����O�w�g�����H�ϥγo���S�ޤF�C\n"NOR);
        if(me->is_busy())
            return notify_fail(HIW"\n�z���b����L���Ʊ���I\n"NOR);
        enemy = me->query_enemy();
        num = random(sizeof(enemy));
        enemy[num]=present(enemy[num],environment(me));
        c=enemy[num]->query_temp("apply/armor");
        hit = random(me->query_dex()*2+sk/3);
        dodge = random(enemy[num]->query_dex()*2+enemy[num]->query_skill("dodge")/2);
        message_vision(HIC"\n$N��M�o�X�@�D�j�j��l, �⤤"+name+"���Q�r�����R,\n"
                       "�A�X�@�D�g��, �Ƥs�ˮ����ĦV$n!!"NOR,me,enemy[num]);
        damage = (skill*3/2) + (da/2) + (random(da)/2) + (random(force)/2);
        damage = damage - (random(c)/2);
        if(damage < 100) damage = 80+random(30);
        if(damage > 350) damage = 300+random(80);
        if(weapon->query("skill_type")=="axe") damage = damage*5/4;
        if(hit-20 > dodge)
        {
            msg = HIR"\n�| -- �| -- ���n�A$n���ݫe���M�h�F��D�ˤf�A��y�p�W�I\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(4)+1);
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(2);
            enemy[num]->start_busy(1);
        }
        else if(hit+15 > dodge)
        {
            msg = HIB"\n$n�����@�{�A�i�O���Q$N���j�j��l���˨���C\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(2)+1);
            // �W�[�����ˮ`���v�T
            damage = damage / 2;
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            enemy[num]->improve_skill("parry",3+random(2));
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(3);
            enemy[num]->start_busy(2);
        }
        else
        {
            msg = CYN"\n���Q$n�{�F�}�h�C\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",1);
            enemy[num]->improve_skill("dodge",3+random(2));
            me->start_busy(3);
            enemy[num]->start_busy(1);
        }
        me->add("ap",-30);
        if(weapon->query("skill_type")=="blade")
            me->improve_skill("blade",2);
        if(weapon->query("skill_type")=="axe")
            me->improve_skill("axe",2);
        return 1;
    }
    if(arg=="all-slash")
    {
        if(!me->is_fighting())
            return notify_fail(HIW"\n�z�����b�԰����~��ϥγo���S�ޡC\n"NOR);
        if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
            return notify_fail(HIB"�z�{�b�èS���b�ϥ�"HIC"�}��N"NOR"��I\n"NOR);
        if(me->query_str() < 55 || force < 70 || sk < 80 )
            return notify_fail(HIW"\n�z����O�٤����H�ϥX�o���S�ޡC\n"NOR);
        if(me->query("ap") < 300)
            return notify_fail(HIW"\n�z����O�w�g�����H�ϥγo���S�ޤF�C\n"NOR);
        if(me->is_busy())
            return notify_fail(HIW"\n�z���b����L���Ʊ���I\n"NOR);
        enemy = me->query_enemy();
        num = random(sizeof(enemy));
        enemy[num]=present(enemy[num],environment(me));
        c=enemy[num]->query_temp("apply/armor");
        hit = random(me->query_dex()*2+sk/3);
        dodge = random(enemy[num]->query_dex()*2+enemy[num]->query_skill("dodge")/2);
        message_vision(HIB"$N�r�M�N�⤤"+name+"�V�a�@�J, ��X���C�ت����g���C\n\n"NOR,me,enemy[num]);
        me->start_busy(3);
        message_vision(HIC"$N�����j�۽ĦV���ߦa�W��"+name+", �a�۱j�j�\\�O\�M���W�����ѱ۫l,\n"
                       "�w�O���ۤg�a�Ȱ_, �o�X�F�����T!"NOR,me);
        for(eny=0;eny<sizeof(enemy);eny++)
        {
            damage = (random(skill)/2) + (random(da)/2) + (force/2);
            if(damage < 30) damage = 25+random(15);
            if(damage > 180) damage = 160+random(40);
            if(weapon->query("skill_type")=="axe") damage = damage*5/4;
            if(hit+15 > random(enemy[eny]->query_dex()*2+enemy[eny]->query_skill("dodge")/2))
            {
                msg = HIY"\n���G$n�{�����ΡA�Q���a�j�j�l�D���g�������I\n"NOR;
                message_vision(msg, me, enemy[eny]);
                me->improve_skill("slash-wood",random(2)+1);
                damage = damage - ((enemy[eny]->query_armor())/2);
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,enemy[eny],damage,"bar");
                enemy[eny]->receive_damage("hp",damage,me);
                COMBAT_D->report_status(enemy[eny]);
                enemy[eny]->start_busy(2);
            }
            else
            {
                msg = YEL"\n$n½���@��A����L�I�����}�F���g�ӨӪ��g�ۡC\n"NOR;
                message_vision(msg, me, enemy[eny]);
                me->improve_skill("slash-wood",1);
                enemy[eny]->improve_skill("dodge",3+random(2));
                enemy[eny]->start_busy(1);
            }
        }
        me->start_busy(2);
        me->add("ap",-(eny*9));
        message_vision(HIR"�g����F����}�g�ӥX�A���V$n�G�h!!!"NOR,me,enemy[num]);
        damage = (random(skill)/2) + (skill/2) + (random(da)/3*2) + (da/3*2) + (force*2/3);
        damage = damage - random(c/2);
        if(damage < 150) damage=140+random(20);
        if(damage > 400) damage=380+random(50);
        if(weapon->query("skill_type")=="axe") damage = damage*5/4;
        if(hit-8 > dodge)
        {
            msg = HIY"����$n���A��g�t�ӥX�I\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(3)+2);
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(2);
            enemy[num]->start_busy(1);
        }
        else
        {
            msg = YEL"�o��$n�{�F�ӯT�V�ҼˡC\n" NOR;
            message_vision(msg, me, enemy[num]);
            enemy[num]->improve_skill("dodge",2);
            me->improve_skill("slash-wood",1);
            me->start_busy(2);
        }
        me->add("ap",-33);
        if(weapon->query("skill_type")=="blade")
            me->improve_skill("blade",3);
        if(weapon->query("skill_type")=="axe")
            me->improve_skill("axe",3);
        return 1;
    }
    if(weapon->query("skill_type")=="blade")
    {
        if(me->query_skill("blade")<15)
            return notify_fail(HIR"�A���M�k����F�I\n"NOR);
    }
    if(weapon->query("skill_type")=="axe")
    {
        if(me->query_skill("axe")<8)
            return notify_fail(HIR"�A����N����F�I\n"NOR);
    }
    if(me->query("ap")<30 || me->query("hp")<30)
        return notify_fail(HIR"�A�w�g�S�O�F�ա��I\n"NOR);
    //�ĤG��exert
    if(me->query_skill_mapped("axe")=="slash-wood" && me->query_skill_mapped("blade")=="slash-wood")
    {
        if( !target ) target = offensive_target(me);
        if(!target) 	return notify_fail(HIG"�A�w�g�b�ϥί}��N�F�C\n"NOR);
        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        c = target->query_armor();
        if(sk > random(225) && me->query("str") > 30 && me->query("ap")>50 && sk > 35)
        {
            message_vision(HIR"\n$N�g�ܤ@�n�A���"+name+"�D�ܪŤ��V$n�g�A�ӤU�I\n"NOR,me,target);
            if(weapon->query("skill_type")=="blade")
                damage = sk + bd;
            if(weapon->query("skill_type")=="axe")
                damage = sk + ax;
            damage = sk + da;
            damage -= (random(c)/2);
            if(damage<50) damage=30+random(30);
            if(damage>220) damage=170+random(70);
            if(weapon->query("skill_type")=="axe")
                damage = damage*5/4;
            if(random(me->query_dex()*2+sk/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
            {
                msg = RED"�| ---- ���@�n�A$n���A���q��$N���y���O�I\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("slash-wood",random(3)+1);
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(2);
            }
            else
            {
                msg = YEL"��$n�ਭ�@�{�A�{�}�F$N�Ӳr�P��աC\n" NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->improve_skill("slash-wood",random(2));
                me->start_busy(2);
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->add("ap",-15);
            if(weapon->query("skill_type")=="blade")
                me->improve_skill("blade",1);
            if(weapon->query("skill_type")=="axe")
                me->improve_skill("axe",1);
            return 1;
        }
        else
        {
            message_vision(HIC"$N�ĤO���|�_�⤤"+name+"��V$n!"NOR,me,target);
            if(weapon->query("skill_type")=="blade")
                damage = (sk/2) + (bd/2) + (da/2);
            if(weapon->query("skill_type")=="axe")
                damage = (sk/2) + (ax/2) + (da/2);
            damage = (random(damage)/2) + damage/3*2;
            damage -= (random(c)/2);
            if(weapon->qeury("skill_type")=="axe")
                damage = damage*5/4;
            if( damage < 30 ) damage = 20 + random(15);
            if( damage > 120 ) damage = 100 + random(30);
            if( random(me->query_dex()*2+sk/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
            {
                msg = HIY"���G�@�۩R���A�y��$n�Q���Y�����A��!!\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("slash-wood",2+random(2));
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                target->start_busy(1);
                me->start_busy(2);
            }
            else
            {
                msg = YEL"���O�o�Q$n�����}�F�C\n"NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->improve_skill("slash-wood",random(2));
                me->start_busy(2);
            }
            me->add("ap",-9);
            me->start_busy(1);
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            if(weapon->query("skill_type")=="blade")
            {
                me->improve_skill("slash-wood",1+random(me->query_int()/8));
                me->improve_skill("blade",1+random(me->query_int()/8));
            }
            if(weapon->query("skill_type")=="axe")
            {
                me->improve_skill("slash-wood",2);
                me->improve_skill("axe",2);
            }
            return 1;
        }
    }
if(!me->skill_active( "slash-wood",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("�A���۪��ʧ@�٨S�����C\n");
    me->map_skill("blade","slash-wood");
    me->map_skill("axe","slash-wood");
    me->reset_action();
    message_vision("\n"HIC"$N���_�⤤"+name+"�A���_"HIR"�}��N"NOR"�C\n"NOR,me);
    me->add("ap",-10);
    me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
    return 1;
}
void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("blade");
        me->map_skill("axe");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="blade" && weapon->query("skill_type")!="axe")
    {
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
    {
        return;
    }
    if(me->query("ap")<40)
    {
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        tell_object(me,HIW"\n�A�w�g�����O�ί}��N�F��C\n"NOR);
        return ;
    }
    if( me->is_fighting() ) me->add("ap",-5); //luky
me->skill_active( "slash-wood",(: call_other, __FILE__, "delay", me, 6 :), 10);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
    int a,b,c;
    a=ob->query_skill("axe");
    b=ob->query_skill("blade");
    c=(a+b)/2;
    if(c>85) c=85;
    return c;
}

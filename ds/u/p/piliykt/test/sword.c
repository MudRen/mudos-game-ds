#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
        ([
        "action": "$N�@���⤤���C�A���]�C�Z�Ĥ@�ۡy"HIR"�s�]�ûR"NOR"�z\n�C�Ʀ����I�ե��V$n������

��h",
        "damage": 50,
        "dodge" : 140,
        "attact_type":  "bar", 
        "damage_type":  "���",
        ]),                                                            
        ([
        "action": "$N�ϥX���]�C�Z�ĤG�ۡy"HIW"�D���]��"NOR"�z�A�������@�ۡA\n�k��ߨ�X$n���`�N

���ڬ�V$n���Y��",
        "damage":                80,
        "dodge" :                100,
        "parry" :               20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@�Ӱ��B���X���]�C�Z�ĤT�ۡy"HIB"���]���"NOR"�z�A\n  �⤤���C���M�����V$n��

�I����h",
        "damage":                100,
        "dodge" :                150,
        "parry" :                -40,
        "attact_type":  "bar",
        "damage_type":  "�C��",
        ]),

        ([
        "action": "$N���Ѥ@���A���]�C�Z�ĥ|�ۡy"HIG"���]����"NOR"�z�A\n�������O�����b�C���A�V$n��

�����h",
        "damage":                160,
        "dodge" :                -30,
        "parry" :                -5,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
});

int exert(object me, object target, string arg)
{
        int a,c,i,j,k,damage,sk,lvtest,pcost,basicd;
        string msg;
        object weapon, wp;
        mapping type;
    
        weapon=me->query_temp("weapon");
        if( !weapon || weapon->query("skill_type")!="sword")
        // change by alick
                 return notify_fail("���]�C�Z�S���C�A�Ϥ��X�ӡH\n");
        if(arg=="off" )
        {
        if( me->query_skill_mapped("sword")!="masen_sword")
            return notify_fail("�A�èS���ϥΡu���]�C�Z�v�C\n");
        me->map_skill("sword");
        me->reset_action();
        write("�C�Z�u���]�C�v�w�����C\n");
        return 1;
        }

        if(me->query_skill("sword")< 10) 
                return notify_fail("�A���C���Z�����Ѥ����H�ϥΡu���]�@�v�C\n");
        if(me->query("ap")<30 || me->query("hp")<100) 
                return notify_fail("�A�����骬�p�L�k�ϥκ��]�C�Z�C\n");

        //�ĤG��exert
        if(me->query_skill_mapped("sword")=="masen_sword")
        {
        if( !target ) target = offensive_target(me);
        if(!target)   return notify_fail("�A�w�g�b�ϥΡu���]�C�Z�v�F�C\n");
       
        //�����ʪ��n�S�O�`�N�n�[�U�����.
if( !weapon || weapon->query("skill_type")!="sword") return notify_fail("�A�Τѥ~���P���μC�ڡH

\n");
        if(!me->can_fight(target)) return 0;
        if( !me->is_fighting(target) ) return notify_fail("�A�èS����"+target->query("name")+"��

�����C\n");
    if(target->is_corpse()) return notify_fail("�ݲM���A���v�g���F�C\n");
        sk=me->query_skill("masen_sword");
    if(sk < 80) return notify_fail("�̧A�{�b���\\�O�A�ٵL�k��|�o�۪��u�͡C\n");
    if(me->query_skill("sword") < 70) return notify_fail("�A���C�����ѡA�|�����ܦp��������\\�O�C

\n");
    if(me->query_skill("force") <40) return notify_fail("�A�����O�A�L�k�䴩��p���j�j���������һ�

�C\n");
    if(me->query_temp("masen") > 0) return notify_fail("�A�L�k�A�u�ɶ�����X�ĤG�������ۡC\n");
        damage = 300 + random(sk + me->query_damage());
message_vision(HIR"\n$N�@���R�ѡA�I�i�X�W�j���ޡA�ǻ������]�C�Z�����ޡi�ѥ~���P�j�I\n"NOR,me);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);  
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);  
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);  
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���ѦV$N���X�ĳ����y"HIR"�s�]�ûR"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�ਭ�V$N���X�ĶL���y"HIW"�D���]��"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"���e�V$N���X�İ����y"HIB"���]���"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIR"�s��V$N���X�ĸv���y"HIG"���]����"NOR"�z�A�y��$N����@�B�C�ˡI\n"NOR,target);
message_vision(HIW"\n�q�@�y��$N"HIR+damage+HIW"�I�ˮ`�A�ïd�F�@�Ѯ�b$N�餺�I�r\n"NOR,target);
        target->start_busy(1);
     target->receive_damage("hp",damage, me);
     target->set("wound/head",random(3));
     me->set_temp("masen",1);
     call_out("stop_masen", 18, me);
        me->start_busy(3);
        me->receive_damage("ap",random(30)+ 10);
//       call_out("nine",12,me,target,1,damage);
                target->apply_condition("sword_gas", 

target->query_condition("sword_gas")+1+random((me->query_skill("masen_sword")/10)-1));
        return 1;
        }
        if(!me->skill_active( "masen_sword",(: call_other, __FILE__, "delay", me ,1:), 2))
        return notify_fail("�A�������@�k�٨S�����C\n");
        me->map_skill("whip", "masen_whip");
        me->reset_action();
message_vision("\n"HIY"$N�E���������O�A�H��R�F�@�ӼC��A�K�}�l�I�i�y���]�C�Z�z�I\n"NOR,me);
                me->receive_damage("ap",10);
        me->start_busy(1);
        return 1;
}
void nine(object me,object target,int l,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       l=me->query_skill("masen_sword");
       msg = "�u��$n����Ÿ�ݡA�f���R�X�@�f�A��A$N������"HIY"�i"CYN"�ѥ~���P"HIY"�j"NOR"�A\n";
       msg += "�����z�g�A$n��������z�X�F�@���j�j����������I\n\n";
       msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w"HIW"�i"CYN"�ѥ~�E���P"HIW"�j"HIY"�w�w�w�w�w�w�w�w�w

�w�w�w�w�w��\n";
       message_vision(msg, me, target);
       if( l/3 + random(l) > random(target->query_skill("dodge")) )
       {
damage = me->query_skill("sword") + random(me->query("str")) -     target->query_armor()/2 - 

random(target->query_armor()/2) - (target->query("con"));
         if(damage<20) damage=15+random(8);
message_vision(HIR "\n���G�q$n���W�z�X�������W�����a���@�Ѧ��A�ݨӨ��ˤ����C\n" NOR,me,target);
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            target->receive_damage("hp",damage,me);
            target->receive_damage("ap",random(damage));
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                 tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                 tell_object(target,HIR"("+damage+")"NOR+" 

("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);
       }
       else {
message_vision(HIW "\n$n�j�奢��A�b�@�����A�i�{�X�@�����Z���\\�O�A����g�I�A����F���W�������~��        a=75+a;
        return a;
}

���X�C\n" NOR,me,target)
       if(!me->is_fighting(target)) me->kill_ob(target);     
       
int valid_learn(object me) {    return 1;   
mapping query_action(object me, object weapon
    return action[random(sizeof(action))]
void stop_masen(object me
        if( !me ) return
        me->delete_temp("masen")
int practice_skill(object me) { return 1; 
int improve_limite(object ob
        int a
        a=ob->query_int()

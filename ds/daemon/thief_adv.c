// �{�N���|¾�~�H���֤� (�p�����|-Thief)
// �s�g��: Luky 1999.9.5
//
// �p�����|_�i���� -Tmr 2002/04/04

/*   �S��\��
 * �@�B�I��s���ޥ��G �b�I�릨�\��A���i��h1~2 �^�X������
 * 
 * �G�B���ѡG�i �j�� ���w�˳ƪ��Z���B���� //���}��
 */
#include <weapon.h>
#include <combat.h>
#include <ansi.h>

void create()
{
        seteuid(getuid());
}

void show_damage(object me,object target,int damage)
{
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
}

int do_help(object me,string arg)
{
 if(arg=="advanced thief")
 {
  tell_object(me,@HELP

        ���O                    ����
        ==================      ===============================================
        help advance thief      ���������C

        stillhunt <id>          �ѭI�᰽ŧ�W��<id>���Ǫ��Ϊ��a�A���M����O
                                ��褣�`�N�A�A�άݤ���A�C��ŧ���\�ɡA��
                                ���|�X��設�ߨ��l�����p�U�A�F��h�������C


        Edit By Tmr 2002/04/04
HELP
  );
  return 1;
 }
 return 0;
}

/* �i���I��GStillhunt */
int do_backstab(object me,string arg)
{
        object target,weapon;
        int sk,cost;

        if(!me) return 0;
        if(!arg) return notify_fail("�A�n����֡S\n");
        sk=me->query_skill("backstab");
        cost=5+sk/3;
        if(!weapon=me->query_temp("weapon"))
                return notify_fail("�A�S�����Z���p��I��?\n");
        if(!weapon->can_stab() )
                 return notify_fail(weapon->name()+"�ä��A�X�ΨӭI��C\n");
        if(me->is_busy() || me->is_block())
                return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
        if( me->is_fighting() )
                 return notify_fail("�A���b�԰��S�ŭI��C\n");
        if(sk<1)
                 return notify_fail("�A���٨S�ǹL�I��C\n");
        if((int)me->query("ap")< cost || (int)me->query("mp")< cost/2 )
                return notify_fail("�A���믫��O���ΡA�L�k�I��C\n");
        target = present(arg, environment(me));
        if(!target) 
                return notify_fail("�A�n����֡S\n");
        if(!living(target) )
                return notify_fail("�ݲM���@�I, ���ä��O����.\n");
        if(!me->can_fight(target))
                return me->can_fight(target);
        if(target->visible(me))
                return notify_fail("��西�`���ۧA�A�A�S�����|�I��C\n");
        /* �i���I��n�D���������c�� */
        if(me->query("evil")< -200)
                return notify_fail("�A�ӵ��}�F�A���ԤߤU��C\n");
        
        if(random(target->query_dex()/4+target->query_skill("perception")/3)
                > random(sk/2+me->query_dex()/3+me->query_temp("hide")*4)
        )
        {
                me->delete_temp("hide");
                message_vision(HIW"$N"HIW"�Q�q�I�᰽ŧ$n"HIW"�A���O�o�Q$n"HIW"�o�{�F�I�I\n"NOR,me,target);
                me->improve_skill("backstab",2+random(2+me->query_int()/10));
                target->kill_ob(me);
                if(me->query_skill("free_action")>69) me->add_busy(1); //�ޯ� free_action �ΨӴ�֦��L�ɶ�
                if(me->query_skill("free_action")>39) me->add_busy(2); //�ޯ� free_action �ΨӴ�֦��L�ɶ�
                else me->add_busy(3);
                return 1;
        }
        tell_object(me,CYN "�A��"+weapon->name()+CYN"�A�p���l�l�a�V"+target->name()+CYN"���I�ᱵ��...\n\n"NOR);
        me->receive_damage("mp",cost/2);
        me->receive_damage("ap",cost);
          me->add_busy(2);
        call_out("bs",3+random(2),me,target);
        return 1;
}


void bs(object me,object target)
{
        int damage,exp,sk,c;
        object weapon;
        if(!me || !target) return;
        if(!weapon=me->query_temp("weapon"))
        {
                tell_object(me,"�A�{�ɨ��U�Z���A���F�o������ʡC\n");
                 return;
        } else if(!weapon->can_stab())
                {
                        tell_object(me,"�A���p�߮����F�Z���A���F�o������ʡC\n");
                        return;
                }
        
        if(environment(me) != environment(target) || !me->visible(target))
        {
                tell_object(me,"�A���F�o������ʡC\n");
                return;
        }
        me->delete_temp("hide");
        sk=me->query_skill("backstab");
        c=target->query_armor();
        /* �I�릨�\���ˮ`�O�p�� */
        damage=me->query_damage()*3+sk;
        /* �Z�����I��[���ĪG */
        if(weapon->query("backstab_bonus")!=0)
                damage=damage*(100+weapon->query("backstab_bonus"))/100;
        damage=damage/2+random(damage/2);
        damage=damage-c/5-random(c/2);
        if(damage<20)
                damage=20+random(10);
        damage += damage*(me->query("evil")/700);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        /*�@�ѭI�몺�¤O�ӨM�w���o �g��� ���ƶq*/
        exp=damage/2+random(damage/4);
        /*
        if(damage>200)
                msg=RED"$n"RED"�G�s�@�n!! ���W�ٵo�X�@�n�y��!!�z���G�O���Y�H�����n���C"NOR;
        else if(damage > 130)
                msg=HIR"$n"HIR"�@�n�s�z!! �ˤf�`�i�����C"NOR;
        else if(damage > 60)
                msg=HIM"$n"HIM"�j�s�@�n!! �A���q�F�@�a�C"NOR;
        else    msg=HIM"�h��$n"HIM"�z�z�j�s�A�X�G�֭n�����L�h�C"NOR;
        */
        /* �i���I�몺�¤O-�h���I��*/
        message_vision(HIY"\n$N"HIY"��M�X�{�b$n"HIY"������A�|�_"+weapon->name()+HIY"�ΤO����$n"HIY"�I�W��F�U�h!!"NOR,me,target);
        /* ��ܭI��L�{���� �T��*/
        //message_vision("\n"+msg+"\n",me,target);
        target->receive_damage("hp",damage,me);
        show_damage(me,target,damage);
        message_vision("\n",me);
        //if(target->query("hp") > 0)
                COMBAT_D->report_status(target);
        /* �s��I�� */
        if( sk > 60 )
        {
                message_vision(HIY"$N"HIY"��ŧ���\\�A�X��$n"HIY"���ߨ��l�U�A�S�r��@�U�I�I"NOR,me,target);
                damage=damage/3+random(damage/3);
                show_damage(me,target,damage);
                target->receive_damage("hp",damage,me);
                message_vision("\n",me);
                //if(target->query("hp") > 0)
                        COMBAT_D->report_status(target);
                if( sk > 70 )
                {
                message_vision(HIR"$N"HIR"�X��½���٦b$n"HIR"�餺��"
                        +weapon->name() +HIR"�A���G�y����j������ˮ`�C\n"NOR,me,target);
                target->receive_wound("body",1+random(2));
                }
                if( sk > 80 )
                {
                        me->kill_ob(target);
                        me->attack();
                }
                if( sk > 90 )
                {
                        me->attack();
                }
        }

        tell_object(me,HIG"\n(�A���o����ʱo��F"+exp+"�I�g��ȡC)\n"NOR);
        me->add("exp",exp);
        me->improve_skill("backstab",2+random(me->query_int()/2+me->query("level")/2));
        if(target->query("hp") > 0) target->kill_ob(me);
        return;
}


#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("�ں��F�Ӧ���",({"Balgun cannon","cannon"}));
set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�@��Ѣ٭����Ͳ������Z���g��(shoot)�Z���A�i�H�˶�(reload)
�K�o�T���̤l�u�C
LONG);
                set("unit", "��");
                set("rigidity",500);    //�s�W: �w��
                set("material","iron");
//
// ����i�H�O   limit_lv        limit_str 
//              limit_dex       limit_con 
//              limit_int       limit_skill
//
                set("limit_int",8);
                set("limit_dex",7);
                set("limit_str",2);
        }

        set("wield_msg","$N���_�@��$n�A�ñN$n���O�I�˸m�Ѷ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I�˸m�����A���b�ӤW�C\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit     �R���v
//  weapon_prop/parry   �۬[�v
//
        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",8);              //�̤j�˶�q
        init_gun(100);   // �׷i�ˮ`�O=set("weapon_prop/damage", 100);
        setup();
        set("value",3180);
}
int do_shoot(object me,object target)
{
        string msg;
        int damage;
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"��M��"+this_object()->name()+HIW+"���$n"+HIW+"�g�X�F�@";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�o";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="�l�u�T\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 300 )
          {
           message_vision("$N���t��������½�F��ӭo��, �}�G���{�L�F$n���g���C\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 80+damage*3+random(100);
          damage-=target->query_armor()/4-random(target->query_armor()/3);
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(HIW+"$N"+HIW+"��"+this_object()->query_temp("bullet/name")+HIW+"���u�}�F�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision("$N���F�@��, ���Q�{�׮ɫo�w�g�Q"HIW"�F��"NOR", "HIR"���ˤ���"NOR"�C\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}

void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
 if( me->query("mp") < 20 ) return;
 if( random(10) < 6 ) return;
 message_vision("\n"
                        +HIB"$N���ں��F�Ӧ������X�@�D���l�q�y�A����$n�I\n"NOR
                        +HIB"$n�y�ɳQ���l�q�y�����ֵJ����I\n\n"NOR,me,victim);
  victim->receive_damage("hp", 200+random(200),me);
 me->receive_damage("mp",5);
 me->add_busy(1);
return;
}

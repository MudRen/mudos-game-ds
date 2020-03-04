#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("���j",({"gun"}));
set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�@���襩��u�K��ű�y���g���Z��(shoot), �S�Q��i�H�b�F�誺���p�Ӭݨ�o�تF��.
LONG);
                set("unit", "��");
                set("rigidity",100);    //�s�W: �w��
                set("material","iron");
                set("limit_int",10);
                set("limit_dex",10);
                set("limit_str",10);
        }


        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",3);              //�̤j�˶�q
        init_gun(13);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
        set("value",6000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"���_"+this_object()->name()+HIW+"�V$n"+HIW+"�}�F�@";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�ǲӦp����";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="���u�T\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(2);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 300 )
          {
           message_vision("$N�@�����դ���, �{���׶}$n���g��, ���y��w�L�L�@�ܡC\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 80+damage*3;
          damage-=target->query_armor()/4-random(target->query_armor()/3);
       damage=damage + this_object()->query_skill("gun") / 3;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"�����@��, ��"+this_object()->query_temp("bullet/name")+YEL+"�����}�F�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N�j�Y�@��, �y�ɨ��W�h�B�j��, �ݨӨ��ˤ���"NOR"�C\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}
#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("��",({"shootbow"}));
set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�@����u�K��ű�y���g���Z��(shoot), �S�Q��i�H�b�F�誺���p�Ӭݨ�o�تF��.
LONG);
                set("unit", "��");
                set("rigidity",90);    //�s�W: �w��
                set("material","wood");
                set("limit_int",4);
                set("limit_dex",4);
                set("limit_str",6);
        }


        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",1);              //�̤j�˶�q
        init_gun(12);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
        set("value",3000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"���_"+this_object()->name()+HIW+"�V$n"+HIW+"�g�h�@";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�������L�۪�";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="���b�T\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(2);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(me->query_skill("gun")+me->query("dex")+random(20) < target->query_skill("dodge")+target->query("dex")+random(40))

          {
           message_vision("$N�@�����դ���, �{���׶}$n���g��, ���y��w�L�L�@�ܡC\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage= this_object()->query_temp("bullet/damage");
          damage= 50+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/4);
       damage=damage + this_player()->query_skill("gun") / 3;
          if(damage<5) damage=random(10);
          if(damage<5)
          {
           message_vision(YEL+"$N"+YEL+"�����@��, �k�u�e��, ���N"+this_object()->query_temp("bullet/name")+YEL+"����U�F�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N�j�Y�@��, ���b����$N, �ݨӨ��ˤ���"NOR"�C\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(1)+1,me);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}
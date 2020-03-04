#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(MAG"�¾K�j�G�N"NOR,({"anesthetize gun","gun"}));
set_weight(12700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
TEST�Z��.
LONG);
                set("unit", "��");
                set("rigidity",90);    //�s�W: �w��
                set("material","iron");
                set("limit_int",15);
                set("limit_str",10);
        }

        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",5);              //�̤j�˶�q
        init_gun(16);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
        set("value",5000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"�|�_"+this_object()->name()+HIW+"�V$n"+HIW+"�g�X�@";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�o�������r��";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="�·��u�T\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
  if(me->query_skill("gun")+me->query("dex")+random(40) < target->query_skill("dodge")+target->query("dex")+random(20))
          {
           message_vision("$N�@�����դ���, �{���׶}$n���g��, ��O�w�ᬰ����!\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 100+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/3);
       damage=damage + this_player()->query_skill("gun") / 3 * 2 ;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"�����@��, �^���@��"+this_object()->query_temp("bullet/name")+YEL+"�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N�j�Y�@��, ���M�P���@�n, �l�u���J�o�\\!"NOR"�C\n",target,me);
          target->receive_damage("hp",damage,me);
          target->start_busy(10);
          if(random(10) == 1 ) target->receive_wound("random",random(2)+1,me);
          target->add_busy(10);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}


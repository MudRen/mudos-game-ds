#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(CYN"�Q�r�}"NOR,({"crossbow"}));
set_weight(5700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�@���襩��u�K��ű�y���g���Z��(shoot), �񩸤S�h�F�X�����ˤO.
LONG);
                set("unit", "��");
                set("rigidity",110);    //�s�W: �w��
                set("material","iron");
                set("limit_int",9);
                set("limit_dex",10);
                set("limit_str",9);
        }


        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",3);              //�̤j�˶�q
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
          msg=HIW+"$N"+HIW+"���_"+this_object()->name()+HIW+"�V$n"+HIW+"�g�X�@";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�������ֳt��";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="���b�T\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(me->query_skill("gun")+me->query("dex")+random(40) < target->query_skill("dodge")+target->query("dex")+random(40))
          {
           message_vision("$N�@�����դ���, �{���׶}$n���g��, �[���w�ᬰ�T�V!\n"+NOR,target,me);
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
           message_vision(YEL+"$N"+YEL+"�����@��, �{���׹L"+this_object()->query_temp("bullet/name")+YEL+"�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N�j�Y�@��, ���M�P���@�n, �b�����J�o�\!"NOR"�C\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(2)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}
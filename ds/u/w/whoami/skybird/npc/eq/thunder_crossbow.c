#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
        set_name(HIB"�p��Q�r�}"NOR,({"thunder crossbow","crossbow"}));
        set("long","�@�⥭�Z�L�_���}�A�ߤ@�S���B�u�����e�ݪ��i���T�աA�@���}�b�g�X\n" 
                   "�N�|�o�X�����p�����n�T�A���ĤH�����ұ��E\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5700);
                set("unit", "��");
                set("value",4000); 
                set("volume",5);
        }

        set("rigidity",110);    //�s�W: �w��
        set("material","iron");
        set("limit_int",45);
        set("limit_dex",45);
        set("limit_str",65); 
        set("limit_lv",35);
        set("bullet_type","small");     //�i�Τl�u����
        set("max_load",20);              //�̤j�˶�q
        init_gun(15);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
}

int do_shoot(object me,object target)
{
        string msg;
        int damage,time,times,delay;
        times = random(me->query_skill("gun")/40 + me->query("dex")/30)+1;
        if(times>3) times=3;

          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-times);
          msg=HIW+"$N"+HIW+"���_"+this_object()->name()+HIW+"�V$n"+HIW+"�g�X"+chinese_number(times);
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="�������ֳt��";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
                else msg+="���b�T\n"+NOR; 
           tell_object(target,"�A�Q���䪺�p���n���_���A�@�ɤ���ʼu�K\n");
           delay = random(me->query("Merits/bio"))+1;
           if(delay>3) delay=3;           target->start_busy(delay); 

          if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1+random(3));

       for (time=0;time<times;time++)
         {     
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          damage=this_object()->query_temp("bullet/damage");
          damage=60+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/3);
          damage=damage + this_player()->query_skill("gun") / 3 * 2 ;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"��b���l, �{���׹L"+this_object()->query_temp("bullet/name")+YEL+"�C\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me); 
           return 0;

          }
          if(me->query_skill("gun")*2+me->query("dex")+random(40)+me->query("Merits/tec")*10 
          < target->query_skill("dodge")+target->query("dex")+random(40)+target->query("int") )
          {
           message_vision("$N�@�����դ���, �{���׶}$n���g��, �[���w�ᬰ�T�V!\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
          } else {
          message_vision(HIR"$N�j�Y�@��, ���M�P���@�n, �b�����J�o�\\!!"NOR,target,me); 
          if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
          tell_object(target,HIR"("+damage+")\n"NOR);
          if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
          tell_object(me,HIR"("+damage+")\n"NOR);

          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) {
          target->receive_wound("random",random(2)+1,me);
          target->add_busy(random(1));
          }
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me); 
          }
         }
         return 1;
}


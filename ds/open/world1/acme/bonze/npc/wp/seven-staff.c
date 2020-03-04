#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"�C�C����"NOR,({"seven staff","staff","_SEVEN_STAFF_"}));
        set("long",
          "�@��O���D�D����ܪ��]���A�������Q�εL�d���Ĵ��ҦӦ��A�o������\n"
        "�ͤ��o��ͧ�L�A�ݵۧ��Wį�ʪ���{���Y�A�A���T�����ߴH�C\n"
        );
          set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "��");
         set("value",5000);
        set("material","copper");
          set("volume",3);
            set("limit_level",10);
        }
        set("weapon_prop/int",2);
        init_staff(32);
        setup();
} 

void attack(object me,object target)
{
        object ob;
        ob=this_object();
    if(!me) return;
        if(random(10)>7 && me->query_skill("staff") > 40)
        {
                message_vision(HIR"\n$N"+HIR"�W�Y�����F�~�۵o�X�@�n�Y�~���n����\n"NOR,ob);
                ob->add("staff-use",1);
                if(random(3)==2) {
                        if(random(me->query_int() ) < random(10) ) return;
                        tell_object(target,CYN "�A�uı�o�����@�}���V....\n" NOR);
                        target->start_busy(1);
                }
                else  {
                if( random(me->query_int()) < random(30)  ) return;
                        tell_object(me,GRN "�A�uı�o�@�ѴH�y�q�⤤���C�C�����Ǩ��餺�I�I\n" NOR);
                        me->receive_heal("ap",1 + me->query_int()*2 );
                        me->receive_heal("mp",1 + me->query_int()*2 );
                }

              if( ob->add("staff-use") > me->query("level")*3 )
              { 
                        message_vision(GRN"\n$N�⤤��$n"+GRN"�Ʀ��@�}�g�ϡA���������F..\n"NOR,me,ob);
                        ob->unequip();
                        destruct(ob);
                }
      }
        return;
}


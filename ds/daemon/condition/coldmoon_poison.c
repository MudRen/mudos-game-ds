//�N��H�r -By Tmr-

#include <ansi.h>

int update_condition(object me, int duration)
{
        int r;
          r=me->query_temp("coldmoon_poison");
        if( r > 0)
        {
                duration -=r;
                  me->set_temp("coldmoon_poison",0);
        }

        if( duration < 1 ) return 0;

          me->receive_damage("hp", 80);
        me->receive_damage("ap", 30);
          me->receive_damage("ap", 50);
           me->start_busy(1);

        tell_object(me, HIW "�@�}�S�@�}���H�𪽽ħA���ߺۡI�I\n" NOR );
      if(me->query("race")=="�H��" || me->query("race")=="human" )
        message_vision("$N�Ϻ����⪺�O�qݳ�ۤߺۡA�y�W�����]���k�h����o�D�`�����C\n",me);
   else
         message_vision("$N�o�X�@�n�D�`�k�h���q�n�I�I\n",me);
        me->apply_condition("coldmoon_poison", duration -1);
        if( duration < 1 ) return 0;
        return 1;
}


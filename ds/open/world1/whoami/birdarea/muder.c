#include <ansi2.h>
        
int room_effect(object me)
{
       if(!userp(this_player())) return 0;
       switch(random(10))
        {
         case 0..1: 
             message_vision(HIC"���D��������ﭱ�ӨӡA$N�չϱ���f��K\n"
                            HIG+"���O�ȶȧl�J�@�f�N�w�g��$N�Y������F�K\n"NOR,me);
             me->add_busy(random(2));
             me->receive_damage("hp",random(100));
             me->receive_damage("ap",random(100));
             me->receive_damage("mp",random(100));
         break;
         case 2:
         message_vision("$N�����}���C�C���J�d�h���K�K\n",me);
         if(me->query_skill("dodge")< 35 && random(10)<3 )
           {
             tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
             me->add_busy(5);
           }
           else if(me->query_skill("dodge")< 70 && random(10)<3 )
           {
             tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
             me->add_busy(3);
           }
           else if(me->query_skill("dodge")>69 && random(10)<3 )
           {
             tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
             me->add_busy(1);
           }
        break;
        default:
        break;
        }
}


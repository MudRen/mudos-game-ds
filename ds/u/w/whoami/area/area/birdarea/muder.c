#include <ansi.h>
        
int room_effect(object me)
{
       if(!userp(this_player())) return 0;
       switch(random(10))
        {
         case 0..1: 
message_vision(HIC"難聞的刺鼻臭味迎面而來，$N試圖掩住口鼻••\n"
                  +"但是吸了一口就已經讓$N頭昏眼花了•••\n"NOR,me);
         me->add_busy(random(2));
         me->receive_damage("hp",random(100));
         me->receive_damage("ap",random(100));
         me->receive_damage("mp",random(100));         case 2:
         message_vision("你的雙腳正慢慢陷入泥沼中．．．。\n",me);
         if(me->query_skill("dodge")< 35 && random(10)<3 )
           {
             tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
             me->add_busy(5);
           }

           else if(me->query_skill("dodge")< 70 && random(10)<3 )
           {
             tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
             me->add_busy(3);
           }
           else if(me->query_skill("dodge")>69 && random(10)<3 )
           {
             tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
             me->add_busy(1);
           }
           return 1;
        default:
        return 1;
        }
}


#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
string *dodge_msg = ({
 "$n一招「迴影幻雲」在$N攻擊過來的剎那，以間不容髮的距離閃過！！\n",
 "$n右腳往左腳一併，一招「影沒無形」整個身體輕輕平移了半寸，使$N的攻擊落空。\n",
 "$n順著$N的攻勢左右迴旋，前後飄移，正是一招「影\隨\身\轉\」！！\n",
 "$n右手一晃，左手一擺，趁$N稍有分心，一招「虛影無體\」輕\悄\悄的轉到$N背後。\n",
 "$n腳一跨，身一縮，「夜林藏影」使整個人輕輕的鑽入$N攻勢的死角中。\n",
});
int exert(object me, object target, string arg)
{
	
	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="shadow_step")
			return notify_fail("喂！你睡迷糊了啊！你根本沒在用影藏步啊！\n");
		me->map_skill("dodge");
		me->reset_action();
                       if(me ->query_temp("skill/shadow_step")>0)
                        {
                             me->set_temp("invis",0);
                             me->delete_temp("skill/shadow_step");
                         }
		message_vision("\n"HIC"$N低首閉目，緩緩吐納，腳步慢慢放輕，左右一轉，停止了「影藏步」\。\n"NOR,me);
		return 1;
	}
            if(arg=="hint off")
             {                         
                           if(!me ->query_temp("skill/shadow_step")>0)  return notify_fail("嗯﹗擺個POSE﹗讓大家看看你並沒有躲起來喔﹗\n");
                        
                             me->set_temp("invis",0);
                             me->delete_temp("skill/shadow_step");
                             message_vision(HIB"\n$N突然從黑暗的角落緩緩走出。\n"NOR,me);

                             return 1;
                  }
            if(arg=="hint" )
           {
                if((me->query_skill("shadow_step")+me->query_skill("dodge"))<77) //dodge夠也可以使用這招
                   return notify_fail("努力，努力，再努力﹗不久的將來你一定可以使用「謎蹤虛影」﹗\n");
                if(me->query_temp("skill/shadow_step")>0) 
                   return notify_fail("相信自己吧﹗你的確已經藏好了﹗\n");
                if( me->query_skill_mapped("dodge")!="shadow_step")
                    return notify_fail("你不用「影藏步」怎麼使用「謎蹤虛影」啊﹖\n");
                  if( me->is_fighting() ) 
	 {
	                if(!target) target = offensive_target(me);
                              if(!target) return 0;
                         if(me->query_skill("shadow_step")<71) return notify_fail("你還沒有到可以在戰鬥中使用「謎蹤虛影」的地步。\n");
                        message_vision(CYN"\n$N突然一縮身，使一招「謎蹤虛影」﹗躲到附近的黑影之中﹗\n"NOR,me);
		        me->receive_damage("ap",7+random(3));  //用了這招會損 ap 和 mp
                                   me->receive_damage("mp",50+random(3)); 
                                me->remove_all_killer();
                                target->remove_all_killer(); 
                          me->set_temp("invis",random(2)+1);
                          me->set_temp("skill/shadow_step",1);
                       return 1;
	 }
                else
                        {
                         message_vision(CYN"\n$N使出影藏步的「謎蹤虛影」，瞬間整個人就這樣消失不見了。\n"NOR,me);
                          me->receive_damage("mp",7+random(3));
                          me->set_temp("invis",random(1)+1);
                          me->set_temp("skill/shadow_step",1);
                        	return 1;
                        }
           }
	if(me->query_skill("dodge")<5) return notify_fail("嗯！不是要傷你的心，但是你的Dodge實在不夠喔！\n");
	if(me->query_skill_mapped("dodge")=="shadow_step")
		return notify_fail("不要緊張，放輕鬆。看清楚，你已經在用「影藏步」了喔！\n");
	if(me->query("ap")<5 || me->query("hp")<10) return notify_fail("你累啦！兩腳不聽使喚，已經使不出「影藏步」的輕快了。\n");
        if(!me->skill_active( "shadow_steps",(: call_other, __FILE__, "delay", me ,3:), 3))
                return notify_fail("別急別急，欲速則不達啊！\n");
	me->map_skill("dodge","shadow_step");
	me->reset_action();
	message_vision(HIC"$N一跨一轉使出了「影藏步」，整個身型變得飄移不定。\n"NOR,me);
	me->receive_damage("ap", 3);
	me->receive_damage("mp", 3);
	me->start_busy(1);
	return 1;
}

void delay(object me,int cost)
{
        int a;
        a=me->query_skill("shadow_step");
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="shadow_step")
	{
	 return;
	}
	if(me->query("ap")<10)
	{
	 	me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIB"$N腳步一滯，身型一跌，用不出「影藏步」了……\n"NOR,me);
		tell_object(me,"你還有體力的話，可以開始考慮轉進。\n");
		return;
	}
      if ( me->is_fighting() ) me->receive_damage("ap",7); 
        me->skill_active( "shadow_step",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
        if(ob->query("adv_class")==1) return 70; 
        else return 97;                         
}
/*
      影藏步，是講究敵我之間微妙變化的身法，經由一些小動作干擾彼此之間的關係而趁機
       製造閃避的機會。其招式多半出乎意料，應退則進，應左則右，看來似乎是自己往敵招
       衝去，實則是敵招之隙正於敵招之中，故以進為退。多半也有可使敵人出乎意料的效果
       。學習影藏步之人，甚至可以將這種講究微妙變化的特點運用在隱藏身型之上，聽說練
       到某種程度的人甚至可以在戰鬥中影藏自己的身型以脫離戰鬥。
*/
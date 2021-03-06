//cloudsteps.c
//QC: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
string *dodge_msg = ({
 "$n大步一躍，一式"CYN"「平步青雲」"NOR"閃到$N的斜後方。\n",
 "$n縱身一跳，一招"CYN"「一躍登天」"NOR"跳至半天高閃開$N的攻擊。\n",
 "$n腳步放慢，以"CYN"「幻雲悠悠」"NOR"不急不徐的速度閃開$N的攻勢。\n",
 "$n忽然加快速度，一招"CYN"「紫霞靈彩」"NOR"就讓$N眼花撩亂了。\n",
 "$n身形後移數丈，"CYN"「柔離飄風」"NOR"一招使$N的殺招鞭長莫及。\n",
});
int exert(object me, object target, string arg)
{
	string msg;
	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="cloudsteps")
			return notify_fail("你並沒有在使用翔雲步法。\n");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIC"$N腳步放慢，停止運行縱雲五行功\。\n"NOR,me);
		return 1;
	}
	if(me->query_skill("dodge")<5) return notify_fail("你的縱躍之術還太差。\n");
	if(me->query_skill_mapped("dodge")=="cloudsteps")
		return notify_fail("你已經在使用翔雲步法了。\n");
	if(me->query("ap")<15 || me->query("hp")<10) return notify_fail("你的體力已經不夠了。\n");
        if(!me->skill_active( "cloudsteps",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("你仍在使用翔雲步法中。\n");
	me->map_skill("dodge","cloudsteps");
	me->reset_action();
	message_vision(HIC"$N雙腳一揚，兩個翻身以後準備好使出『翔雲步法』。\n"NOR,me);
	me->add("ap", -2);
	me->start_busy(1);
	return 1;
}

void delay(object me,int cost)
{
        int a;
        object target;
        a=me->query_skill("cloudsteps");
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="cloudsteps")
	{
	 return;
	}
	if(me->query("ap")<10)
	{
	 	me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIB"$N兩腳漸漸落地，無法使用翔雲步法了。\n"NOR,me);
		tell_object(me,"你的體力已經不夠了。\n");
		return;
	}
        if( me->is_fighting() ) 
	{
		if( a > random(250) && me->query_skill("dodge")>70 &&
                    me->query("ap") > 100 && me->query("mp") > 100 ) {
	                if(!target) target = offensive_target(me);
                        if(!target)
                        {
                        	me->receive_damage("ap",2); //這行是本來應該要損的
                        	me->skill_active( "cloudsteps",(: call_other, __FILE__, "delay", me ,cost:), 5);
                        	return;
                        }
                        message_vision(CYN"\n$N瞬間疾轉方位九處，繞得$n頭昏眼花，"NOR,me,target);
		        me->receive_damage("ap",8+random(3));  //用了這招會損 ap 和 mp
                        me->receive_damage("mp",8+random(3)); 
                        if(random(me->query_dex()*2+a/3)+5>random(target->query_dex()*2+target->query_skill("dodge")/2))
		        {
			        message_vision(HIC"搞得$N分不清東西南北，昏頭亂向了。\n\n"NOR,target);
			        target->start_busy(2);
                                target->receive_damage("ap",10+random(5)); //中了這招會損人 ap 和 mp
                                target->receive_damage("mp",10+random(5)); //而且會損到破底(就是-1)
		        } else  message_vision(CYN"但$N反應極快，馬上跳出了$n的步伐圈。\n"NOR,target,me);
	        }
		me->receive_damage("ap",2); //這行是本來應該要損的
	}
        me->skill_active( "cloudsteps",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
        if(ob->query("adv_class")==1) return 80; //進階前可練到 80
        else return 90;                         //進階後可練到  90, 突顯強度
}
//cloudmove.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
 "$n�������v�ҽk�A�@�ۡu�g�������v�N��$N���F�ӪšC\n",
 "$N��ı���e�@���ۼv�A�L�k�i��A��ӳo�O$n���u���v�p�Ρv�C\n",
 "$n�}�B�@���A�����ϥX�u�����궳�v��$N����۸��šC\n",
 "$n���w���ʡA�ΥX�@���u���Φp���v�A���Q$N������$n�o���n�L�ʡI\n",
 "$n�����k�@�A���ΫᲾ�A�@���u�@���K�G�v�N$N�������x�ƨ��}�C\n",
});
int exert(object me, object target, string arg)
{
	string msg;
        int speed,b;
        speed = (int)me->query_skill("dodge");
        speed = speed/13;
        b=(int)me->query_temp("skill/ghostspeed");
	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="cloudmove")
			return notify_fail("�A�èS���B���a������\\�C\n");
		if( me->query_temp("ghostmove")==1 )
			return notify_fail("�ЧA������B��ⶳ���v�C\n");	
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIC"$N�}�B��C�A����B���a������\\�C\n"NOR,me);
		return 1;
	}
	if(arg=="ghostmove")
	{
		if( me->query_skill_mapped("dodge")!="cloudmove")
			return notify_fail("�A�èS���B���a������\\�C\n");
                if( me->query_temp("ghostmove")==1 )
			return notify_fail("�A�w�g�ϥX�ⶳ���v�o���S�ޤF�C\n");
		if( me->query_skill("dodge") < 90 || me->query_skill("cloudmove") < 80 )
			return notify_fail("�A����O�٤����ϥέⶳ���v�C\n");
                if( me->query("ap") < 500 )
                        return notify_fail("�A����O�w�g�����ϥέⶳ���v�F�C\n");
                message_vision(HIM"\n$N�l���}�L�A�����B���A��B�_�ⶳ���v���ޡC\n"NOR,me);
                me->set_temp("skill/ghostmove",1);
                me->set_temp("skill/ghostspeed",speed);
                me->add("ap",-400);
                me->start_busy(2);
                me->add_temp("apply/dex",speed);
                return 1;
	}        
	if(arg=="off_ghostmove")
	{

		if( me->query_temp("skill/ghostmove")!=1 )
			return notify_fail("�A�èS���b�ϥέⶳ���v�C\n");
		message_vision(HIM"\n$N���h�}�U����Aí���ΡA����B��F�ⶳ���v�C\n"NOR,me);
		me->delete_temp("skill/ghostmove");
                me->delete_temp("skill/ghostspeed");
		me->start_busy(2);
		me->add_temp("apply/dex",-(b));
		return 1;
	}
	if(me->query_skill("dodge")<70) return notify_fail("�A���a�D���N�٤Ӯt�C\n");
	if(me->query_skill_mapped("dodge")=="cloudmove")
		return notify_fail("�A�w�g�B���a������\\�F�C\n");
	if(me->query("ap")<100 || me->query("hp")<20) return notify_fail("�A����O�w�g�����F�C\n");
        if(!me->skill_active( "cloudmove",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("�A�٦b�B���a������\\��C\n");
	me->map_skill("dodge","cloudmove");
	me->reset_action();
	message_vision(HIY"$N�}�l�@�ݡA���Τ@�ơA�}�l�B�_�a������\\�C\n"NOR,me);
	me->add("ap", -4);
	me->start_busy(1);
	return 1;
}

void delay(object me,int cost)
{
        int a;
        a=(int)me->query_temp("skill/ghostspeed");
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="cloudmove")
	{
         me->delete_temp("skill/ghostmove");
         me->delete_temp("skill/ghostspeed");
         me->add_temp("apply/dex",-(a));
	 return;
	}
	if(me->query("ap")<50)
	{
	 	me->map_skill("dodge");
		me->reset_action();
                me->delete_temp("skill/ghostmove");
                me->delete_temp("skill/ghostspeed");
                me->add_temp("apply/dex",-(a));
                message_vision("\n"CYN"$N���ά�M��C�A�ⶳ���v����B��F�C\n"NOR,me);
		message_vision("\n"HIB"$N�}�O�@���A�����k��A�S��k�A�B���a������\\�F�C\n"NOR,me);
		tell_object(me,"�A����O�w�g�����F�C\n");
		return;
	}
	me->add("ap",-3);
        me->skill_active( "cloudmove",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
        int a,b;
        a=ob->query_int();
        b=ob->query_dex();
        a=a+b+30;
        if(a>80) a = 80;
        else if(ob->query("adv_class")==2) return 90; //�i����i�m�� 90
        else return a;                                //�_�h�O 80 �H�U
}

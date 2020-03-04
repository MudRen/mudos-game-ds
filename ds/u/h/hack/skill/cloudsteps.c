//cloudsteps.c
//QC: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
string *dodge_msg = ({
 "$n�j�B�@�D�A�@��"CYN"�u���B�C���v"NOR"�{��$N���׫��C\n",
 "$n�a���@���A�@��"CYN"�u�@�D�n�ѡv"NOR"���ܥb�Ѱ��{�}$N�������C\n",
 "$n�}�B��C�A�H"CYN"�u�۶��y�y�v"NOR"���椣�}���t�װ{�}$N����աC\n",
 "$n���M�[�ֳt�סA�@��"CYN"�u�����F�m�v"NOR"�N��$N���Ἲ�äF�C\n",
 "$n���ΫᲾ�ƤV�A"CYN"�u�X���ƭ��v"NOR"�@�ۨ�$N�������@�����ΡC\n",
});
int exert(object me, object target, string arg)
{
	string msg;
	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="cloudsteps")
			return notify_fail("�A�èS���b�ϥε����B�k�C\n");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIC"$N�}�B��C�A����B���a������\\�C\n"NOR,me);
		return 1;
	}
	if(me->query_skill("dodge")<5) return notify_fail("�A���a�D���N�٤Ӯt�C\n");
	if(me->query_skill_mapped("dodge")=="cloudsteps")
		return notify_fail("�A�w�g�b�ϥε����B�k�F�C\n");
	if(me->query("ap")<15 || me->query("hp")<10) return notify_fail("�A����O�w�g�����F�C\n");
        if(!me->skill_active( "cloudsteps",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("�A���b�ϥε����B�k���C\n");
	me->map_skill("dodge","cloudsteps");
	me->reset_action();
	message_vision(HIC"$N���}�@���A���½���H��ǳƦn�ϥX�y�����B�k�z�C\n"NOR,me);
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
		message_vision("\n"HIB"$N��}�������a�A�L�k�ϥε����B�k�F�C\n"NOR,me);
		tell_object(me,"�A����O�w�g�����F�C\n");
		return;
	}
        if( me->is_fighting() ) 
	{
		if( a > random(250) && me->query_skill("dodge")>70 &&
                    me->query("ap") > 100 && me->query("mp") > 100 ) {
	                if(!target) target = offensive_target(me);
                        if(!target)
                        {
                        	me->receive_damage("ap",2); //�o��O�������ӭn�l��
                        	me->skill_active( "cloudsteps",(: call_other, __FILE__, "delay", me ,cost:), 5);
                        	return;
                        }
                        message_vision(CYN"\n$N�����e����E�B�A¶�o$n�Y������A"NOR,me,target);
		        me->receive_damage("ap",8+random(3));  //�ΤF�o�۷|�l ap �M mp
                        me->receive_damage("mp",8+random(3)); 
                        if(random(me->query_dex()*2+a/3)+5>random(target->query_dex()*2+target->query_skill("dodge")/2))
		        {
			        message_vision(HIC"�d�o$N�����M�F��n�_�A���Y�æV�F�C\n\n"NOR,target);
			        target->start_busy(2);
                                target->receive_damage("ap",10+random(5)); //���F�o�۷|�l�H ap �M mp
                                target->receive_damage("mp",10+random(5)); //�ӥB�|�l��}��(�N�O-1)
		        } else  message_vision(CYN"��$N�������֡A���W���X�F$n���B���C\n"NOR,target,me);
	        }
		me->receive_damage("ap",2); //�o��O�������ӭn�l��
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
        if(ob->query("adv_class")==1) return 80; //�i���e�i�m�� 80
        else return 90;                         //�i����i�m��  90, ����j��
}
//QC: Luky 1999.8.17
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int fistpower=this_player()->query_skill("cloudforce")/10;
void delay(object me,int cost);

mapping *action = ({
	([
	"action": "$N���ɦV�e, ���x�f�����O�V�e�@��, �@�ۡu���e���]�v���V$n",
	"damage":                11+fistpower,
	"attack":                20,
	"attact_type":  "bar",
            "damage_type":  "�x��",
        ]),

	([
	"action": "$N�@�ӽb�B�ĦV$n�o�X�@�ۡu�}����ѡv�ƴx�����e��$n�L��",
    "damage":                13+fistpower,
	"dodge" :               -10,
	"parry" :               -20,
	"attact_type":  "bar",
            "damage_type":  "�W��",
        ]),

	([
	"action": "$N�ޤW�b��½���@��, �����H�@�x�u�Q������v�\\�V\$n����",
	"damage":                11+fistpower,
	"dodge" :               -20,
	"attack":                15,
	"attact_type":  "bar",
        "damage_type":  "����",
        ]),

	([
	"action": "$N����B�ʤ���, �@�ۡu�ѹp�����v�����x�ਭ�A�V$n",
    "damage":                14+fistpower,
	"dodge" :               -25,
	"parry" :               -25,
	"attact_type":  "bar",
	"damage_type": "�A��",
        ]),

	([
	"action": "$N�ਭ�ƩP, �ƼĤ��O���v���O, �@�ۡu�����T�T�v���V$n",
    "damage":                10+fistpower,
	"attack":                20,
	"parry" :                20,
	"attact_type":  "bar",
	"damage_type": "����",
        ]),

	([
	"action": "$N����W�ߪ�����, �զ��u½���ЫB�v�����۲r�M��V$n���W�n�`",
    "damage":                16+fistpower,
	"dodge" :               -10,
	"parry" :               -10,
	"attact_type":  "bar",
	"damage_type": "�x��",
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage,f;
	int hs,sk,force,dodge,hit,num,cf;
	string msg;
	object weapon;
	f=me->query_skill("force")/3;
        cf=me->query_skill("cloudfist");
        sk=me->query_skill("unarmed");
	force=me->query_skill("cloudforce");
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("�A�⤤�����۪Z���A�p��ϥΡu�e���x�k�v?\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("unarmed")!="cloudfist")
			return notify_fail("�A�èS���b�ϥΡu�e���x�k�v�C\n");
		me->map_skill("unarmed");
		me->reset_action();
		write("�A����ϥγe���x�k�F�C\n");
		return 1;
	}
        if(arg=="sky-force")
        {
        	if(!target)
        	{
        		target = offensive_target(me);
        		if(!target) return notify_fail("\n�z�����b�԰����~��ϥΡy�@��e���ѡz�C\n");
        	}
                if(!me->is_fighting(target))
                        return notify_fail("\n�z�����b�԰����~��ϥΡy�@��e���ѡz�C\n");
                if(me->query_skill_mapped("unarmed")!="cloudfist")
                        return notify_fail("�z�{�b�èS���ϥγe���x�k��C\n");
                if( force < 80 || sk < 85 || cf < 80 )
                        return notify_fail("\n�z����\�O�٤����H�ϥX�y�@��e���ѡz�C\n");
                if(me->query("ap") < 500)
                        return notify_fail("\n�z����O�����ϥΡy�@��e���ѡz�C\n");
                if(me->is_busy())
                        return notify_fail(HIW"\n�z���b����L���Ʊ���I\n"NOR);
                //num = random(sizeof(enemy));
                //enemy[num]=present(enemy[num],environment(me));
                //c=enemy[num]->query_temp("apply/armor");
                c = target->query_armor(); //luky
                hit = random(COMBAT_D->attack_factor(me,"unarmed")); //luky
                dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
                message_vision(HIM"$N�𾮤߯��A���E���x�A�j�ܹD�G\n\n"NOR+
                               HIC"           �y"HIY"�����L�ܶ��Aĭ�����u��\n"NOR+
                               HIY"             �զ��s���q�A�@��e���ѡI"HIC"�z\n\n"NOR+
                               HIG"�����A�j�j��l�p�Ƥs�ˮ����է�V$n�I\n"NOR,me,target);
                damage = ((sk + force)*2) + random(me->query_damage()) + me->query_damage()/2;
		damage = (damage*3)/2;
                damage -= (random(c/2) + c/2);
                if(damage < 150) damage = 140+random(30);
                if(damage > 900) damage = 900+((damage-900)/5);
				if(hit + 50> dodge)
                {
                        msg = HIR"        ���G�R��$n�A�u�M�աv�@�n�A$n�n�ɤf�Q�A��I\n\n"NOR;
                        message_vision(msg, me, target);
                        me->improve_skill("cloudfist",random(4)+(me->query_int()/5));
                        // �W�[�����ˮ`���v�T
                        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(3);
                        target->start_busy(2);
                }
                else
                {
                        msg = MAG"        ��$n�榣�ਭ�@�{�A�׶}�F�r�P���@�ۡC\n\n"NOR;
                        message_vision(msg, me, target);
                        me->improve_skill("cloudfist",2);
                        target->improve_skill("dodge",3+random(2));
                        me->start_busy(3);
                }
                //me->add("ap",-225-(damage/8));
                me->receive_damage("ap",200+damage/10+random(20));
                me->improve_skill("unarmed",3+(me->query_int()/5));
                return 1;
        }
	if(me->query_skill("unarmed")<11) 
                return notify_fail("�A���Ť�i����¦�����A�L�k�ϥΡu�e���x�k�v�C\n");
        if(me->query("ap")<20 || me->query("hp")<15) 
                return notify_fail("�A�����骬�p�Ӯt�F�A����ϥΡu�e���x�k�v�C\n");
        if(!me->skill_active( "cloudfist",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("�A����ϥγe���x�k���ʧ@�٨S�����C\n");
	me->map_skill("unarmed", "cloudfist");
	me->reset_action();
	message_vision(HIC"\n$N�l�E���⤧�W�A�ϰ_�u�e���x�k�v�C\n"NOR,me);
    	me->receive_damage("ap",5);
	me->start_busy(2);
        return 1;
}

void delay(object me,int cost)
{
	object weapon,*enemy;
        string *limbs;
        int c,cs,cf,force,count,num,eny,i,j,damage,hit,dodge,steps,lv;
	lv=me->query("level");
        cf=me->query_skill("cloudfist");
        force=me->query_skill("cloudforce");
        steps=cs=me->query_skill("cloudsteps");
	if(!me) return;
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed")
		{
	 	 me->map_skill("unarmed");
		 me->reset_action();
		 return;
		}
	}
	if(me->query_skill_mapped("unarmed")!="cloudfist")
	{
	 return;
	}
        if(me->query("ap")<15)
	{
	 	me->map_skill("unarmed");
		me->reset_action();
		tell_object(me,"\n�A����O�����A����A�Ρu�e���x�k�v�F�C\n");
		return;
	}
        if( me->is_fighting() )
        { 
		if( me->query_skill("force")>25 && cf>random(135) && me->query("ap") > 100)
		{
	                enemy=me->query_enemy();
                        cs=cs/15;
                        if(cs<1) cs=1;
                        if(cs>5) cs=5;
                        for(count=0;count<sizeof(enemy) && count<cs;count++)
                        {
                                limbs = enemy[count]->query("limbs");
                                c=enemy[count]->query_armor();
                                hit = random(COMBAT_D->attack_factor(me,"unarmed")+cf/3);
                                dodge = random(- (COMBAT_D->dodge_factor(enemy[count],"dodge")));
				if(lv>30) lv=30;
                                damage = (steps/2) + (cf/2) + (random(me->query_damage()*5/2) + random(force/2)) + (lv*3);
                                damage -= (c/2 +random(c/3));
                                if(damage < 20) damage = 18+random(5);
				if(damage > 375) damage = 375+((damage-375)/4);
				if(hit + 35 > dodge)
	                        {
		                        message_vision("\n$N��M�o�x��V$n�A$n�{�פ��ΡA�Q�o�ۡy�ƴ����ݡz�����F"+limbs[random(sizeof(limbs))]+"�C\n",me,enemy[count]);
                                        me->improve_skill("cloudfist",random(2)+(me->query_int()/5)); //�S����B�~�W�[
                                        // �W�[�����ˮ`���v�T
                                        damage = COMBAT_D->Merits_damage(me,enemy[count],damage,"bar");
                                        enemy[count]->receive_damage("hp",damage,me);
                                        me->receive_damage("ap",damage/10+random(5));
                                        COMBAT_D->report_status(enemy[count]);
	                        }
	                        else
                                {
                                        message_vision("$N��M�o�x��V$n�A��$n�s�}�o�ۡy�ƴ����ݡz���}��A�{�}�F�o�@�ۡC\n",me,enemy[count]);
                                        enemy[count]->improve_skill("dodge",2);
	                        	me->receive_damage("ap",5+random(5));
	                        }
                                me->improve_skill("unarmed",(me->query_int()/4)+1);
                        }
                }
                me->receive_damage("ap",5); //luky
        	me->improve_skill("unarmed",(me->query_int()/5)+1); //luky
        	me->improve_skill("cloudfist",1+(me->query_int()/5)); //luky �@�ԮɺC�C�W�[
        }
        me->skill_active( "cloudfist",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
        int a;
        a=ob->query_skill("unarmed");
        if(a>80) a=80;
	if(ob->query("adv_class")==2) return 90;
        else if(ob->query("adv_class")==1) return a;
}

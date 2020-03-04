#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
int f=this_player()->query_skill("force")/3;
mapping *action = ({
	([
	"action": "$N���ɦV�e, ���x�f�����O�V�e�@��, �@�ۡu���e���]�v���V$n",
	"damage":                18+f,
	"attack":                20,
	"attact_type":  "bar",
            "damage_type":  "�x��",
        ]),

	([
	"action": "$N�@�ӽb�B�ĦV$n�o�X�@�ۡu�}����ѡv�ƴx�����e��$n�L��",
	"damage":                23+f,
	"dodge" :               -10,
	"parry" :               -20,
	"attact_type":  "bar",
            "damage_type":  "�W��",
        ]),

	([
	"action": "$N�ޤW�b��½���@��, �����H�@�x�u�Q������v�\\�V\$n����",
	"damage":                13+f,
	"dodge" :               -20,
	"attack":                15,
	"attact_type":  "bar",
        "damage_type":  "����",
        ]),

	([
	"action": "$N����B�ʤ���, �@�ۡu�ѹp�����v�����x�ਭ�A�V$n",
	"damage":                25+f,
	"dodge" :               -25,
	"parry" :               -25,
	"attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

	([
	"action": "$N�ਭ�ƩP, �ƼĤ��O���v���O, �@�ۡu�����T�T�v���V$n",
	"damage":                10+f,
	"attack":                20,
	"parry" :                20,
	"attact_type":  "bar",
        "damage_type":  "����",
        ]),

	([
	"action": "$N����W�ߪ�����, �զ��u½���ЫB�v�����۲r�M��V$n���W�n�`",
	"damage":                30+f,
	"dodge" :               -10,
	"parry" :               -10,
	"attact_type":  "bar",
        "damage_type":  "'�x��",
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	int hs,sk,force,dodge,hit,num,cf;
	string msg;
	object weapon,*enemy;
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
                if(!me->is_fighting())
                        return notify_fail("\n�z�����b�԰����~��ϥΡy�@��e���ѡz�C\n");
                if(me->query_skill_mapped("unarmed")!="cloudfist")
                        return notify_fail("�z�{�b�èS���ϥγe���x�k��C\n");
                if( force < 80 || sk < 85 || cf < 80 )
                        return notify_fail("\n�z����O�٤����H�ϥX�y�@��e���ѡz�C\n");
                if(me->query("ap") < 450)
                        return notify_fail("\n�z����O�����ϥΡy�@��e���ѡz�C\n");
                if(me->is_busy())
                        return notify_fail(HIW"\n�z���b����L���Ʊ���I\n"NOR);
                enemy = me->query_enemy();
                num = random(sizeof(enemy));
                enemy[num]=present(enemy[num],environment(me));
                c=enemy[num]->query_temp("apply/armor");
                hit = random(me->query_dex()*2+sk/3);
                dodge = random(enemy[num]->query_dex()*2+enemy[num]->query_skill("dodge")/2);
                message_vision(HIM"$N�𾮤߯��A���E���x�A�j�ܹD�G\n\n"NOR+
                               HIC"           �y"HIY"�����L�ܶ��Aĭ�����u��\n"NOR+
                               HIY"             �զ��s���q�A�@��e���ѡI"HIC"�z\n\n"NOR+
                               HIG"�����A�j�j��l�p�Ƥs�ˮ����ե�$N�o�X��V$n�I\n"NOR,me,enemy[num]);
                damage = ((sk + force)*2) + random(me->query_str()*2) + me->query_damage();
                damage = damage - (random(c)/2);
                if(damage < 150) damage = 140+random(30);
                if(damage > 600) damage = 600+((damage-600)/5);
                if(hit + 20> dodge -20)
                {
                        msg = HIR"        ���G�R��$n�A�u�M�աv�@�n�A$n�n�ɤf�Q�A��I\n\n"NOR;
                        message_vision(msg, me, enemy[num]);
                        me->improve_skill("cloudfist",random(4)+(me->query_int()/5));
                        // �W�[�����ˮ`���v�T
                        damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
                        enemy[num]->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(enemy[num]);
                        me->start_busy(4);
                        enemy[num]->start_busy(2);
                }
                else
                {
                        msg = MAG"        ��$n�榣�ਭ�@�{�A�׶}�F�r�P���@�ۡC\n\n"NOR;
                        message_vision(msg, me, enemy[num]);
                        me->improve_skill("cloudfist",1);
                        enemy[num]->improve_skill("dodge",3+random(2));
                        me->start_busy(5);
                }
                me->add("ap",-225-(damage/8));
                me->improve_skill("unarmed",3+(me->query_int()/5));
                return 1;
        }
	if(me->query_skill("unarmed")<11) 
                return notify_fail("�A���{������|���ݥ[�j�A�ثe�|�����H�ϥΡu�e���x�k�v�C\n");
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
        int c,cs,cf,force,count,num,eny,i,j,damage,hit,dodge,steps;
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
		if( me->query_skill("force")>25 && me->query_skill("unarmed")>20 && 
                    me->query_skill("cloudfist")>random(200) && me->query("ap") > 100)
		{
	                enemy=me->query_enemy();
                        cs=cs/15;
                        if(cs<1) cs=1;
                        if(cs>5) cs=5;
                        for(count=0;count<sizeof(enemy) && count<cs;count++)
                        {
                                limbs = enemy[count]->query("limbs");
                                c=enemy[count]->query_temp("apply/armor");
                                hit = random(me->query_dex()*2+cf/3);
                                dodge = random(enemy[count]->query_dex()*2+enemy[count]->query_skill("dodge")/2);
                                damage = (steps/3) + (cf/2) + random(me->query_damage()/4) + (force/2);
                                damage = damage - (c/3);
                                if(damage < 20) damage = 18+random(5);
                                if(damage > 150) damage = 150+((damage-150)/5);
	                        if(hit > dodge)
	                        {
		                        message_vision("\n$N��M�o�x��V$n�A$n�{�פ��ΡA�Q�o�ۡy�ƴ����ݡz�����F"+limbs[random(sizeof(limbs))]+"�C\n",me,enemy[count]);
                                        me->improve_skill("cloudfist",random(2)+(me->query_int()/5));
                                        // �W�[�����ˮ`���v�T
                                        damage = COMBAT_D->Merits_damage(me,enemy[count],damage,"bar");
                                        enemy[count]->receive_damage("hp",damage,me);
                                        COMBAT_D->report_status(enemy[count]);
	                        }
	                        else
                                {
                                        message_vision("$N��M�o�x��V$n�A��$n�s�}�o�ۡy�ƴ����ݡz���}��A�{�}�F�o�@�ۡC\n",me,enemy[count]);
                                        enemy[count]->improve_skill("dodge",2);
	                        }
                                me->receive_damage("ap",5+(damage/10));
                                me->improve_skill("unarmed",(me->query_int()/7)+1);
                        }
                }
                me->receive_damage("ap",5); //luky
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

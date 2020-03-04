#include <ansi.h>;
inherit SKILL;
inherit SSERVER;

mapping *action = ({
(["action": "$N�ϥX�@���u���E�{�@���v,��$w���ѦӤU,��$n��$l�A�h",
"damage":                60,
"dodge" :               -30,
                "damage_type":  "�A��"
        ]),
(["action":"$N�����, �@�ۡu���P���ܡv,$w�����Ʀ��|�D�C��,
�|�D�C�𪽮g�V$n��$l",
                "damage":    40,
                "dodge" :    30,
                "attack":    30,
                "damage_type":  "���"
        ]),
(["action":"$N�ϥX�u�@�C�ʪe�s�v,�⤤����$w, �o�X�j�j�C��g�V$n��$l",
                "damage": 60,
                "parry": -10,
]),
(["action":"$N�R�ƼC��, �@�����ۡy�F�p�u�_�ѡz,$w���C�b�W�UŸ��,�Φ��@���q��
�ʦ�$n���h��,�L�ƪ��C���V$n���U�j�n��",
"damage": 100,
"attack": -40,
"dodge" : -30,
"damage_type":  "���"
        ]),
(["action":"$N�B�X�u�B�������H�v�@��, $w�C�~�������z�H�H�H��ŧ�V$n��$l",
"damage":  50,
"dodge":   20,
"attack": -20,
"damage_type":  "���"
	]),
(["action":"$N�ϥX�@�ۡu�����P�p�K�v,$N�N�P���������$w����, �A½$w�j��,
���X�����C���V$n",
"damage":  60,
"dodge":  -10,
"attack": -10,
"parry":  -10,
"damage_type":  "���"
	]),
(["action":"$N�ϥX�u��~�p�i�s�v,$N�⤤$w�J�M�@��, �j���V�e���X
�j�j��~, ����V$n��$l",
"damage":  50,
"attack": -20,
"damage_type":  "���"
	]),
(["action":"$N�����ݰ�, �\\�O\����$w����, ���ۡy�g���}�s�١z�@���o�X�j�j�C��,
��������$n��$l�g�A�ӥh",
"damage": 144,
"dodge":  -10,
"attack":  10,
"damage_type":  "���"
	]),
});
int test(object me,object target)
{
    if(random(300)>200) {
	string msg;
        int damage,c,force;
	if ( !force ) force = me->query("force_factor");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�y�嶧�C�g �B��i�p�z�u���԰��������ϥΡC\n");
	if( me->query("hp") < 200 || me->query("mp") < 160 )
                return notify_fail("�A����O�ΥͩR�O�w�g�����F.\n");
        if( me->query_skill("thundersword") < 40 )
		return notify_fail("�A���ʹp���C�ۦ��٤������, �L�k�ϥX�y�嶧�C�g �B��i�p�z.\n");
	if( me->query_skill("force") < 40 )
		return notify_fail("�A�����\�����`�p, �򥻨Ϥ��X�y�嶧�C�g �B��i�p�z.\n");
	msg = HIC "$N�ϥX�ʹp���C�����ޡM�y�嶧�C�g �B��i�p�z\n���ѷ��a���¤O��V$n!!�M";
	c = target->query_temp("apply/armor");
        if ( c > 150 ) c = 150;
	damage = (me->query_skill("thundersword")*4)+((((300+random(300))*me->query("mp"))/me->query("max_mp")));
	damage = (damage + ((damage * force)/100)) - (c*2);
        if ( damage < 500 ) damage = 350 + random(150);
	me->start_busy(1);
        me->add("mp",-65+(-65*force));
        me->add("hp",-50+(-50*force));
	if( 22 + random(me->query_skill("thundersword")) > 43 ) {
		msg += "���G$p�Q$P�����A���T\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage);
	} else {
		msg += "�i�O�Q$p���{�F�}�h�C\n" NOR;
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target,1);
	return 1;
}
}
int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
	return notify_fail("�A�S�����C�A�p��m�ʹp���C�H\n");

	if( (int)me->query("max_mp") < 300 || (int)me->query("mp") < 100 )
	return notify_fail("�A�����O�����M�S����k�m�ʹp���C�C\n"); 
       return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("dex")<40)  
	if( (int)me->query("int")<30)
		return notify_fail("�A����O����,���A�X�ǳo���C�k�C\n");
        me->add("mp",-50);
        write("�A���۩Ҿǽm�F�@�M�C�ۡC\n");
        return 1;
}

string perform_action_file(string action)
{

   return "/daemon/skill/thundersword/" + action;
}

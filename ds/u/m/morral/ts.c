#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
([
	"action": "$N�ϥX�@���u"HIM"���E�{�@��"NOR"�v,��$w���ѦӤU,��$n�A�h",
	"damage":                50,
	"dodge" :               -30,
        "damage_type":  "�A��"
        ]),
([
	"action":"$N�����, �@�ۡu"HIW"���P����"NOR"�v,$w�����Ʀ��|�D�C��,
�|�D�C�𪽮g�V$n",
        "damage":    35,
        "dodge" :    30,
        "damage_type":  "���"
        ]),
([
	"action":"$N�ϥX�u"HIY"�@�C�ʪe�s"NOR"�v,�⤤����$w, �o�X�j�j�C��g�V$n",
        "damage": 30,
        "damage_type":  "���"
]),
([
	"action":"$N�R�ƼC��, �@�����ۡy"HIW"�F�p�u�_��"NOR"�z,$w���C�b�W�UŸ��,�Φ��@���q��
�ʦ�$n���h��,�L�ƪ��C���V$n���U�j�n��",
	"damage": 80,
	"dodge" : -30,
	"damage_type":  "���"
        ]),
([
	"action":"$N�B�X�u"HIC"�B�������H"NOR"�v�@��, $w�C�~�������z�H�H�H��ŧ�V$n",
	"damage":  50,
	"dodge":   20,
	"damage_type":  "���"
	]),
([
	"action":"$N�ϥX�@�ۡu"HIR"�����P�p�K"NOR"�v,$N�N�P���������$w����, �A½$w�j��,
���X�����C���V$n"+NOR,
	"damage":  60,
	"dodge":  -10,
	"damage_type":  "�N��"
	]),
([
	"action":"$N�ϥX�u"HIG"��~���i�s"NOR"�v,$N�⤤$w�J�M�@��, �j���V�e���X
�j�j��~, ����V$n",
	"damage":  50,
	"damage_type":  "���"
	]),
([
	"action":"$N�����ݰ�, �\\�O\����$w����, ���ۡy"HIM"�g"HIC"��"HIR"�}"HIG"�s"HIW"��"NOR"�z�@���o�X�j�j�C��,
��������$n�g�A�ӥh",
	"damage": 90,
	"dodge":  -10,
	"damage_type":  "�Y�����"
	]),
});

int exert(object me, object target,string dir)
{
	int damage,c,str,a,i,j;
	string msg;
	mapping type;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("�ʹp���C�u���ͪ��ϥΡC\n");
	}
	if(environment(me)->query("no_fight") || environment(me)->query("no_kill"))
		return notify_fail("�o�̸T��԰��T\n");
	if((int)me->query("mp") < 40 || (int)me->query("hp") < 20)
		return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
	if(!weapon=me->query_temp("weapon")) return notify_fail("�S���Z���p��I�i�C�ۡT\n");
	if(weapon->query("skill_type")!="sword") return notify_fail("�ʹp�C�k�����t�X�C�ϥΡT\n");
	if(userp(me) && userp(target))	//�������@�w�n�]�w
	{
	  if(me->query("level") < 5 ) return notify_fail("�A�ثe�����Ť��i�H�������a�T\n");
	  if(target->query("level") < 5 ) return notify_fail("�A���i�H�����p���C���Ū����a�T\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	}
	
	message_vision(HIW"$N�B�_�ʹp�C�Z, �C���p�{�q��E�g�ӥX�T�T\n\n"NOR,me);
	c = target->query_armor();
        
      if(random(me->query_skill("thundersword"))> 50 && me->query("hp")<me->query("max_hp")/2)
      {
      	msg = HIC "$N�ϥX�ʹp���C�����ޡy�g�p�C ����z�M\n���ѷ��a���¤O��V$n!!�M";
	damage = me->query_skill("thundersword") + me->query_str() * 4 + me->query("mp");
	damage -= random(target->query_armor());
	if(damage<150) damage=100+random(80);
	me->start_busy(1);
        if( 22 + random(me->query_skill("thundersword")) > 44 )
        {
		msg += "���G$p�Q$P�����A���T\n" NOR;
		target->start_busy(2);
                target->receive_damage("hp",damage,me);
	} else {
		msg += "�i�O�Q$p���{�F�}�h�C\n" NOR;
	}
	message_vision(msg, me, target);
      }
      else
      {
	i=me->query_skill("thundersword")/12;
	if(i>10) i=10;
	if(i<1) i=1;
	
	for( a=0; a<i; a++ )
	{
		j=random(sizeof(action));
		type=action[j];
		msg = type["action"]+NOR+", ";
		msg = replace_string( msg, "$w", weapon->name() );
		damage = (me->query_str()+me->query_skill("thundersword"))-random(c);
		damage += type["damage"];
        	if( damage < 1 ) damage = random(20);
		if( random(me->query_dex()+me->query_skill("thundersword")/2) > random(target->query_dex()+target->query_skill("dodge")/2)+type["dodge"]
		 && damage>0)
		{
			msg += HIR"���G�y��$n�@�B"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
                	target->receive_damage("hp",damage,me);
		} else {
			msg += "�i�O�Q$n���{�F�}�h�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
	 }
       }
	COMBAT_D->report_status(target);
	message_vision("\n",me);
	me->improve_skill("thundersword",1+me->query_int()/10);
	if(!me->is_fighting(target)) me->kill_ob(target);
	if(!target->is_fighting(me)) target->kill_ob(me);
	me->start_busy(2);
	me->add("hp",-20);
	me->add("mp",-40);
	return 1;
}

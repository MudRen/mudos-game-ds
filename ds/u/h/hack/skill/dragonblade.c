//QC : Luky
#include <ansi.h>
#define DELAY 
inherit SKILL;
inherit SSERVER;
int fo=this_player()->query_skill("force")/3;
mapping *action = ({
([
	"action": "$N�@���u����ѲP�v���$w�A�H�N���������V$n��$l",
	"damage":                fo,
	"dodge" :                20,
	"attack":                20,
	"attact_type":  "bar",
        "damage_type":  "���"
        ]),
([
	"action":"$N���$w�M�ۤj�}�j�X�A�@���u�s�C�|��v��V$n��$l",
        "damage":     15+fo,
        "dodge" :    -10,
	"attact_type":  "bar",
        "damage_type":  "���"
        ]),
([
	"action":"$N���ⴤ��$w�A���ۡu�C�s����v�����j�P�M����V$n��$l",
        "damage": 45+fo,
        "attack": 10,
	"attact_type":  "bar",
        "damage_type":  "���"
]),
([
	"action":"$N�a���b�Ѱ��A�@�ۡu���s�ϧ��v�A��$w�j���V�U���$n��$l�٥h",
	"damage": 35+fo,
	"dodge" : -10,
	"attact_type":  "bar",
	"damage_type":  "�A��"
        ]),
([
	"action":"$N���u�y�P�l��v�@�X�A$w���M�ճs����������$n��$l��h",
	"damage":  10+fo,
	"parry":  -10,
	"attact_type":  "bar",
	"damage_type":  "���",
	]),

});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,db,bd,b,d,e,da,f,roll;
 string msg,aa;
 object weapon;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 db = me->query_skill("dragonblade");
 bd = me->query_skill("blade");
 f= me->query_skill("force");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("blade")!="dragonblade")
   return notify_fail("�A�èS���b�ϥιC�s�M�k�C\n");
  me->map_skill("blade");
  me->reset_action();
  write(YEL"�A��U�⤤���M�A���ϥιC�s�M�k�F�C\n"NOR);
  return 1;
 }
 if(!weapon || weapon->query("skill_type")!="blade") 
  return notify_fail("���ΤM�A�p��ϥX�M�k�H�A�H���A�j��i�H�{��o�X�M��ڡH\n");
 if(bd < 45)
  return notify_fail("�A���򥻤M�k�ޥ������A�p��ϥιC�s�M�k�H\n");
 if(me->query("ap")<80 || me->query("hp")<50)
  return notify_fail("�A�����骬�p����ϥΦ��M�k�C\n");
 //�ĤG��exert
 if(me->query_skill_mapped("blade")=="dragonblade")
 {
  if( db < 80 || bd < 80 || f < 50)
   return notify_fail("�A����O�٤����A����ιC�s�M�k�����ޡC\n");
  if( me->query("hp") < 40 || me->query("ap") < 150 )
   return notify_fail("�A�����骬�p�w�g�Ӯt�F�A����ιC�s�M�k�����ޡC\n");
  if( !target ) target = offensive_target(me);
  if( !target )	return notify_fail("�A�w�g�b�ϥιC�s�M�k�F�C\n");
  //�����ʪ��n�S�O�`�N�n�[�U�����.
  if( !me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  c = target->query_armor();
  damage = da + (db*3/2) + f + random(me->query_str()*2) + random(me->query_con()*2) + random(f/2) + random(da/2);
  damage = damage * 4 / 5;
  if( damage > 600 ) damage = 600 + random((damage-600)/4);
  if( damage <  50 ) damage = 46 + random(10);
  a=damage/150;
  if( a < 1 ) a=1;
  message_vision(HIC"\n$N�N��W��"+weapon->query("name")+HIC+"���ʤK��A���k�j�ۡA���������M����¶�I\n"NOR,me);
  message_vision(RED"�ƹD��l�k�p���M���V$N�g�b�ӥh�I\n\n"NOR,target);
  for(e=0;e<a;e++)
  {
   message_vision(HIY"�@�D�M�𭸦V$N�����W�I"NOR,target);
   if(random(COMBAT_D->attack_factor(me,"blade")) + (db*2/3) > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
   {
    msg = HIR"���G$n�Q�o�D�M��夤�F�I\n"NOR;
    message_vision(msg, me, target);
    me->improve_skill("dragonblade",(me->query_int()/25) + random(2));
    me->improve_skill("blade",1 + random(2));
    // �W�[�����ˮ`���v�T
    damage = (damage / a) + (a*25) + random(me->query_dex()*2/3) - (c/3);
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->add_busy(random(2));
   }
   else
   {
    msg = YEL"���G�Q$n�a���{�}�F�C\n"NOR;
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    me->improve_skill("blade",1);
   }
  }
  if(!me->is_fighting(target)) me->kill_ob(target);
  if(!target->is_fighting(me)) target->kill_ob(me);     
  me->receive_damage("ap",15+(a*13));
  me->improve_skill("blade",1);
  me->start_busy(3);
  return 1;
 }
 //fix by luky
 if(!me->skill_active( "dragonblade",(: call_other, __FILE__, "delay", me ,5:), 5))
  return notify_fail("�A�٦b�ϥιC�s�M�k�C\n");
 me->map_skill("blade","dragonblade");
 me->reset_action();
 message_vision("\n$N�⤤��"+weapon->query("name")+NOR+"��M�H���@�{�A$N�B�_�F"HIC"�C�s�M�k"NOR"�C\n",me);
 me->receive_damage("ap",15);
 me->start_busy(2);
 return 1;
}
void delay(object me,int cost)
{
	object weapon,target;
	int roll,dex,db,f,hit,dodge,c,b,d,damage;
	dex=me->query_dex();
	db=me->query_skill("dragonblade");
	f=me->query_skill("force");
	weapon=me->query_temp("weapon");
	if(!me) return;
	if(!weapon)
	{
	 	me->map_skill("blade");
		me->reset_action();
		return;
	}
	if(weapon->query("skill_type")!="blade")
	{
	 	me->map_skill("blade");
		me->reset_action();
		return;
	}
	if(me->query_skill_mapped("blade")!="dragonblade")
	{
	 return;
	}
        if(me->query("ap")<55)
	{
	 	me->map_skill("blade");
		me->reset_action();
		tell_object(me,"\n�A�����O�w�g�����A�L�k�ϥιC�s�M�k�F�C\n\n");
		return ;
	}
        if( me->is_fighting() && !me->is_busy() ) 
	{
		roll = random(100);
		if( !target ) target = offensive_target(me);
                if( db>40 && roll > 59)
		{
			message_vision(CYN"$N�N�⤤��"+weapon->query("name")+CYN+"����ư�A�p���L��V$n���h�I\n"NOR,me,target);
			me->improve_skill("dragonblade",1 + (me->query_int()/10));
			me->improve_skill("blade",1 + random(2));
			c=target->query_armor();
			b=db/30;        
//����
			for(d=0;d<b;d++)
			{
				if(random(COMBAT_D->attack_factor(me,"blade")) + (db*2/3) > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
				{
		               		message_vision(HIR"$N�Q���������F�@�M�I\n"NOR,target);
                              		me->improve_skill("dragonblade",random(1)+(me->query_int()/20)); //�S����B�~�W�[
                               		// �W�[�����ˮ`���v�T
					damage = (db/5) + (f/5) + (random(db+f)/5)+dex+random(dex)+random(me->query_damage()/3);
					damage = damage - (c/5) - random(c/5);
					if(damage < 20) damage = 17 + random(6);
					if(damage > 200) damage = 200 + ((damage-200)/4);
                               		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                               	 	target->receive_damage("hp",damage,me);
                                	COMBAT_D->report_status(target);
				}
				else
				{
				        message_vision(HIG"$N������֡A�{�}�F�ӶաC\n"NOR,target);	
				}
			}
			me->receive_damage("ap",20*b);
		}
		me->receive_damage("ap",4); //luky
	}
        me->skill_active( "dragonblade",(: call_other, __FILE__, "delay", me ,cost:), 5);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
        int a,b;
        if( ob->query("adv_class")==1 ) return 80;
        else return 95;  //�̰��m��95
}

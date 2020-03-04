#include <weapon.h>
#include <ansi.h>
#include <skill.h>
inherit SSERVER;
inherit HAMMER;
void create()
{
	set_name("�p�Τ�s��L", ({ "small wood abacus","abacus" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@�ӭp�⪫�~�ƶq�λ����ɱ`�`�|�Ψ쪺��L�A\n"
                            "���L�A�o�o�{�o�Ӻ�L����]���G�i�H�u�g(throw)�X�h�C\n");
		set("value", 500);
		set("material", "wood");
		set("capacity",115);
		set("can_load","small");
		set("can_shoot",1);
		set("need_skill",10);
		set("is_abacus",1);
        }
    set_temp("abacus/damage",10);
    set_temp("abacus/unit","��");
    set_temp("abacus/name","�p��]");
    set_temp("abacus/type","small");
    set_temp("loaded",115);
    init_hammer(10);
    setup();
}
void init()
{
	add_action("do_throw","throw");
}
int do_throw(string arg,object me)
{
	object target,weapon;
	string msg,damagemsg;
	int damage;
   	me=this_player();
        weapon=me->query_temp("weapon");
	if(!weapon) return 0;
	if(!weapon->query("can_shoot"))
		return notify_fail("�A�ثe�ϥΪ���L����u�g��]�C\n");
	if(this_object()->query_temp("loaded") < 1 )
		return notify_fail("�A����L�w�g�ŤF�C\n");
	if( me->is_busy() )
		return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M����u�g��]�C)\n");
	if( me->query_skill("finger") < 3 ) // �o�䱱��O����
		return notify_fail("�̧A�����k�٤���u�g��]..\n");
	if( me->query_skill("finger") < (this_object()->query("need_skill")/3)+random((this_object()->query("need_skill")*2/3)) ) //��������
	{
		this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
		me->receive_damage("hp",this_object()->query_temp("abacus/damage"));
		return notify_fail("�A�����k�����, ���p�߼u��F�ۤv.\n");
	}
	if(!arg) target = offensive_target(me);
	else target = present(arg, environment(me));
	if( !target ) return notify_fail("[shoot] error: �䤣��ؼСC\n");
	if(	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("[shoot] error: �u���ͪ��g���C\n");
	}
	if( me->is_ghost() ) return notify_fail("�A�{�b�٬O����a�C\n");
	if(userp(me) && userp(target))	//�������@�w�n�]�w
	{
	  if(me->query("level") < 5 ) return notify_fail("�A�ثe�����Ť��i�H�������a�T\n");
	  if(target->query("level") < 5 ) return notify_fail("�A���i�H�����p���C���Ū����a�T\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	}
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg="$N���l�@��, �O�e"+this_object()->name()+"���W, �����V$n�u�X�@";
	  if(stringp(this_object()->query_temp("abacus/unit"))) msg+=this_object()->query_temp("abacus/unit");
		else msg+="��";
	  if(stringp(this_object()->query_temp("abacus/name"))) msg+=this_object()->query_temp("abacus/name")+"!\n"+NOR;
		else msg+="��]!\n"+NOR;
	  if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  me->improve_skill("finger",1+random(me->query_int()/6));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,"finger")+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 150 )
	  {
	   message_vision("$N�ਭ�@�{�A���}�F���g�ӨӪ���]�C\n",target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   return 1;
	  }
	  damage=this_object()->query_temp("abacus/damage")+this_object()->query("weapon_prop/damage");
	  damage= damage*2/3+random(damage/3)+(me->query_skill("finger")/3);
	  damage-=target->query_armor();
	  damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
	  if(damage<1)
	  {
	   message_vision("$N�j�ܤ@�n, �~�M��"+this_object()->query_temp("abacus/name")+"�w�ͥͪ������}�F�C\n",target);
	   target->improve_skill("parry",2+random(target->query_int()/5));
	   return 1;
	  }
	  if(damage < 10) damagemsg = "$N���L���ˮ`�C";
	  else if(damage < 40) damagemsg = "$N�@�B�ˮ`�C";
	  else if(damage < 80) damagemsg = "$N�@�B�Y�������ˡC";
	  else if(damage < 150) damagemsg = "$N�@�B�Q���Y�������ˡI";
	  else if(damage < 250) damagemsg = "$N�@�B�D�`�Y�������j�ˮ`�I";
	  else if(damage < 350) damagemsg = "$N���˳B�֦��z�}�A�A��g�Q�I�I";
	  else damagemsg = "$N�����˳B��F�ӳz��ӹL��׼ҽk���j�}�I�I";
	  message_vision("$N�{�פ��ΡA�Q"+this_object()->query_temp("abacus/name")+"�g���A�y��"+damagemsg+"\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(damage/20)+1,me);
	  COMBAT_D->report_status(target);
	  return 1;

}
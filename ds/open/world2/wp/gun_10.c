#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("�Ѣ٦۰ʤ�j",({"ck hand gun","gun"}));
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",@LONG
�o�O�@��Ѣ٭����Ͳ��������g��(shoot)�Z��, �i�H�˶�(reload)
�K�o�T���̤l�u�C
LONG);
		set("unit", "��");
		set("rigidity",500);	//�s�W: �w��
		set("material","iron");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_int",8);
		set("limit_dex",7);
		set("limit_str",2);
        }

	set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
	set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//
	set("bullet_type","small");	//�i�Τl�u����
	set("max_load",8);		//�̤j�˶�q
	init_gun(10); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
	set("value",1680);
}
int do_shoot(object me,object target)
{
	string msg;
	int damage;
	
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg=HIW+"$N"+HIW+"�Ψ��p���α��ժ��t��, ��M��"+this_object()->name()+HIW+"���$n"+HIW+"�g�X�F�@";
	  if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
		else msg+="�o";
	  if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
		else msg+="�l�u�T\n"+NOR;
	   if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 200 )
	  {
	   message_vision("$N���t��������½�F��ӭo��, �}�G���{�L�F$n���g���C\n"+NOR,target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	
	  damage=50;
	  damage= damage*2+random(damage);
	  damage-=target->query_armor()/3-random(target->query_armor()/2);
	  if(damage<5) damage=random(10);
	  if(damage<1)
	  {
	   message_vision(HIW+"$N"+HIW+"��"+this_object()->query_temp("bullet/name")+HIW+"���u�}�F�C\n"+NOR,target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	  message_vision("$N���F�@��, ���Q�{�׮ɫo�w�g�Q"HIW"�g��"NOR", "HIR"���ˤ���"NOR"�C\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
	  COMBAT_D->report_status(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  return 1;
}


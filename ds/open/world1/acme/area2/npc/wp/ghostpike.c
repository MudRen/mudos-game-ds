#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
        set_name(HIM"���z���N"NOR, ({ "mo gan she jung","pike","jung","mo","gan","she" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",30);
	       set("limit_skill",40);
	       set("limit_lv",20);
               set("unit", "��");
               set("long", "�o�O��j�۶ǬO�b�@�ʦh�~�e�W���Ф��ɡA\n"
                           "���^���h�A�ѬY�Z�N���R�ٱ����^�Ҷ}�W�Ӧ�\n"
                           "���j�A�̭��äF�@�ʤG�Q���c�F�A���Įɫ¤O\n"
                           "��H�C\n");
            set("value",10000);
	       set("volume",6);
               set("material","blacksteel");
	       set("replica_ob",__DIR__"coldpike");
        }
   set_temp("ghost",120);
   set("weapon_prop/hit",-15);
   set("weapon_prop/dodge",-20);
   set("weapon_prop/con",1);
   init_fork(65,TWO_HANDED);
   setup();
}
void attack(object me,object victim)
{
	int damage,dod;
        ::attack();
        if(!me) return;
        if(!victim) return;
	dod=victim->query_int();
	if( dod>100 ) dod = 100;
	if( me->query("ap") < 100 ) return;
	if( this_object()->query_temp("ghost") < 1 ) return;
	if( random(30) < 25 ) return; 
	if( random(me->query_skill("fork",2)) > random(dod) )
	{
                damage = (me->query_damage()/5)+(this_object()->query_temp("ghost"));
                damage = damage - (victim->query_shield()/3) - random(victim->query_shield()/3);
                damage = COMBAT_D->Merits_damage(me,victim,damage,"bar");
                if(damage > 250) damage = 250+random(10);
                victim->receive_damage("hp", damage, me );
                message_vision("\n"
                +MAG"$N�⤤�����z���N��M�@�}�ݰʡA�X�{�F"+chinese_number(this_object()->query_temp("ghost"))+"�����v���V$n�I\n"NOR
                +HIR"$n�Q�F���񨭡A�����W�U�Q��}�ƳB�I\n\n"NOR
                ,me,victim);
		COMBAT_D->report_status(victim);
                me->receive_damage("ap",12);
		this_object()->add_temp("ghost",-1);
                return;
	}
	else
	{
		message_vision("\n"+MAG"$N�⤤�����z���N��M�@�}�ݰʡA�X�{�F"+chinese_number(this_object()->query_temp("ghost"))+"�����v���V$n�I\n"NOR+
				    HIR+"$n�ߪ������A�榣�⨭���h�ƤV�A���w�C\n"NOR,me,victim);
		me->receive_damage("ap",10);
		victim->add_busy(1);
		this_object()->add_temp("ghost",-1);
		return;
	}
}

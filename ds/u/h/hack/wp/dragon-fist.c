#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
	set_name(HIC"�s���u"NOR,({"dragon fist","fist"}) );
	set("long",@long
�o�O�@��e�s�u�Ϊ�����ΪZ���A���K�����x�����Ѥ�A�󦭦~���C
�|���ɡA�ҨϥΪ��W���Z���C�ǻD���Ѥ崿���Ǧ��s���u�A��j�ǰ��A�W
�D�Q�T��ƦʦW�s��s�F�A�e�ᤣ�X�T�ѡA�n�ɹM�ǪZ�L�A��ϱo�����L
����O���W�߸U�A�����{��L�������C
long
	);
       set_weight(8000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("volume",2);
        set("material","iron");
        set("value",5000);
            set("limit_str",20);
	set("wield_msg",
HIW "$N����M�W�@��$n"HIW+"�A�n��$N���o�X�@�ѻ������A�O�H���H�ӷX�C\n"
NOR);
	}
	set("weapon_prop/hit",10);
	init_fist(45);
	setup();
}

void attack(object me,object target)
{
	int damage,def;

    if(me->query_skill("unarmed") > 50 && me->query_str() > 20 && random(10)<3 )
    {
	message_vision( 
		MAG "\n�u��$N"+MAG "�⤤���s����l����j�{�A�@�D���@�D����l�A������V$n�n�`�I�I\n" NOR
	,me,target);

	damage = me->query_skill("unarmed")/2+me->query_dex()+random(20);
	def = target->query_skill("dodge")/2+target->query_dex()+target->query_int()+random(20);
	def = def/2;
	if(damage-def>0 && random(10)>5)
	{
		damage=damage+me->query_int()+random(20);
		damage=damage-random(target->query_int()*4);
		if(damage < 80) damage = 60+random(60);
		message_vision(HIR "$N�{�����ΡA�K�D�s����l�ӳ�����A�y�ɨ��W�����ֲ֬ݨӶ˱o�����I�I"NOR,target);
		if(me->query_temp("show_damage") || me->query_temp("apply/show_damage") )
			tell_object(me,sprintf("(%s%d"NOR")\n",HIY,damage));
   		if(target->query_temp("show_damage") || target->query_temp("apply/show_damage")  ) 
   			tell_object(target,sprintf("(%s%d"NOR") (%d/%d)",HIR,damage,target->query("hp")-damage,target->query("max_hp")));
		message_vision("\n",me);
		target->receive_damage("hp",damage,me);
	}
	else
	{
		message_vision(HIG "$N���G�s�T���}�s����l����աC\n"NOR,target);
	}
    }
    return;
}

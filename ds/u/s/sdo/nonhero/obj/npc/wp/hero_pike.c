#include <ansi2.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�^�����j"NOR,({"hero pike","pike"}) );
        set("long",@LONG
�^�����j�O�L�W�^���̺٤⪺�Z���F�C�b�Գ��W�ľW���}�A���ıN��
��U�x�����A���M�L�W�^���@�_�إߤF���ֶǻ��A���L�]���g��L�h
�A���G�w�g�a���@�Ǳ���C
LONG
	);
        set_weight(25000);
        if (clonep() )
        	set_default_object(__FILE__);
        else 
	{
        set("unit","��");
        set("value",17000);
        set("volume",5);
        set("material","steel");
        init_fork(62);
        set("replica_ob",__DIR__"longwind_pike");
   	}
        set("weapon_prop/bar",1);
        setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/5 �����v�S��
        message_vision(HIW"$N����ۤ⤤���^�����j�A�o�X�����i���ĤH�Y�����ȡC\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(2);
        return;
}
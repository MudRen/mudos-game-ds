#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("�P��P��",({"sun dagger","dagger"}));
	set("long",@LONG
�o�O�@�����⪺�P���C�A�v����m�N���O�A��@��A�|
���ϥΪ̪��ߤ����ͤ@�Ѳ��W�����N�C
[�i�x�s�˳�]
LONG
);
	set_weight(5600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",3480);
    	set("weapon_prop/bar",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/dodge",5);
    	set("weapon_prop/perception",6);
    	set("weapon_prop/hit",11);
	set("backstab_bonus",36);
	init_dagger(15);
        setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(11)) return; // 1/20 �����v�X�{�S��
	if(me->query("evil")<800)
	{
		tell_object(me,"�A��M���@�ѫܷQ���H������A�A���H����G�V�ӶV���c�F�C\n");
		me->add("evil",random(10));
	}
	return;
}

int query_autoload() { return 1; }


#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
    set_name(HIY"�����P"NOR,({"evil dagger","dagger"}));
	set("long",@LONG
    �o�O���J���F�L���@�ö��A�ϥαj�j���]�O�һs�y�X�ӡC�ѩ��ĭ���j�j��
�]�O�A�]���i�I�i�j�O�������A�O�@��֦����Z���C
LONG
);
	set_weight(6600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",4380);
        set("volume",1);
    set("backstab_bonus",100);
    init_dagger(500);
        setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(11)) return; // 1/20 �����v�X�{�S��
	if(me->query("evil")<800)
	{
		tell_object(me,"�A��M���@�ѫܷQ���H������A�A���H����G�V�ӶV���c�F�C\n");
		me->add("evil",3+random(10));
	}
	return;
}



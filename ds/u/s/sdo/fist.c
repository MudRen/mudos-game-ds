#include <weapon.h>
#include <combat.h>
#include <ansi.h>
inherit FIST;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"�P��"NOR, ({ "night fist","fist" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�o�O�@���`�¦⪺���M�A�֦���H�����ˤO�A���˳ƪ֦̾��G�񯫪�
�O�q�C�ӥB�]�����y�]�z���v�T�A�����]�֦��@�Ǩ��m�O�C
[�i�x�s�˳�]
LONG
);
                set("no_sell",1);
                set("no_sac",1);
		set("no_drop",1);
                set("material", "iron");
        	}
    set("weapon_prop/bar",2);
    set("weapon_prop/hit",10);
    set("weapon_prop/parry",12);
    set("weapon_prop/armor",20);
    set("weapon_prop/shield",2);
    init_fist(60);
    setup();
}

void attack(object me,object victim)
{
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(2)) return; // 1/3 �����v�s��
        COMBAT_D->do_attack(me, victim, this_object(), TYPE_REGULAR);
        return;
}

int query_autoload() { return 1; }

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
        set_name(HIR"���"NOR,({"blood soul","blood","claw","soul","fist"}) );
        set ("long", @LONG
����⪺���M�A��X�|�ڻȥզ⪺�Q���A���M���ݦ����O���
�몺�ު����������J�ϥΪ̪��g�ߤ����A��ϥΪ̳s���@��A
�㦳�j�j���¤O�C
LONG
);
        set_weight(2000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",5000);
        set("material","steel");
        set("volume",3);
        set("no_drop",1);
        }
        set("weapon_prop/bar",1);
        set("weapon_prop/str",2);
        init_fist(60);
        setup();
}

int query_autoload() { return 1; }   


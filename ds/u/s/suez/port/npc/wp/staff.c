#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("���",({"staff"}) );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","�˹����R������A�O�Ψ�����v�Q�B�]�I�B�H�Φۤj���D��C\n");
         set("material","iron");
         set("unit","��");
         set("value",2000);
        }
        set("wield_msg","$N�y�����N$n���F�_�ӡC\n");
        init_staff(10);
        setup();        
}


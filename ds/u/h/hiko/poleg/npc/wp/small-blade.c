#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�y�M",({"blade"}) );
        set("long","�@��i�Hô�b�y�W���M�A�h�b�O�����@���Ϊ��C\n");
      set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
      set("value",1000);
                set("material","iron");
        }
                set("wield_msg","$N��W�@�̡A�����q�󮳰_�F�@��U�Q��$n\n");
                init_blade(15);
                setup();
}


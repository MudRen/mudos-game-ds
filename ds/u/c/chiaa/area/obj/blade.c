#include <weapon.h> 
//weapon�Z��
inherit BLADE;
void create()
{
        set_name("�j�M", ({ "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��ݰ_�Ӭ۷��q���j�M�C\n");
                set("value", 1000);
                set("material", "steel");   //material����steel���K
        }
        init_blade(10);

        set("wield_msg", "$N�q�I���X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n��^�J�I��C\n");
      setup();
}

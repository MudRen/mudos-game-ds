#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�����C", ({ "wind sword", "wind" , "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@���ű�y�����@��C�C\n");
                set("volume",3);
                set("value", 400);
        set("material","iron");
                set("sword",41);
        }
        set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
        init_sword(15);
        setup();
}


#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�g�ФM", ({ "crazy sword", "crazy" , "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@���ű�y�����@��M�C\n");
                set("volume",3);
                set("value", 400);
        set("material","iron");
                set("sword",41);
        }
        set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n���J�y�����M�T�C\n");
        init_blade(15);
        setup();
}


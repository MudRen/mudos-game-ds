// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("���M", ({ "blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�`");
                set("long", "�o�O�@�`�G�̮̪����M�A���q�x�L���`�ƪZ���C\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N�u�|�v���@�n��X�@�`$n���b�⤤�C\n");
                set("unwield_msg", "$N�N�⤤��$n���^�M�T�C\n");
        }
        init_blade(20);
        setup();
}

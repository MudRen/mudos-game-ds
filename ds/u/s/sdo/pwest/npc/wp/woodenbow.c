#include <weapon.h>
inherit BOW;

void create()
{
        set_name("����}",({"wooden bow","bow"}));
        set("long","�o�O�@�����s���}�A�i(shoot)�g�X�b�C\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value",690);
        set("volume",3);
        set("material","wood");
        }
        set("monster_weapon_prop/damage", 20);
        init_bow(20);
        setup();
}

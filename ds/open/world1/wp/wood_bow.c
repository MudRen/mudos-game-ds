#include <weapon.h>
inherit BOW;

void create()
{
        set_name("����}",({"large bow","bow"}));
        set("long","�o�O�@����s���j�}�A�Y���W���b�A�i��(shoot)�g�X�b�C\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value",680);
        set("volume",3);
        set("material","wood");
	}
	set("monster_weapon_prop/damage", 16);
        init_bow(16);
        setup();
}
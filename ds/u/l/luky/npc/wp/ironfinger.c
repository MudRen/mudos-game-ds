#include <weapon.h>
inherit FIST;

void create()
{
set_name("�K���s��",({"iron finger","finger"}));
set("long","�o�O�@��H���K���y���s���K��, �i�H�W�[���Y���ˮ`�O�C\n");
set_weight(4300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",170);
		set("material","iron");
		set("limit_str",4);
		set("limit_dex",4);
              }
init_fist(12); 	// �ˮ`�O=set("weapon_prop/damage", 12);
setup();
}

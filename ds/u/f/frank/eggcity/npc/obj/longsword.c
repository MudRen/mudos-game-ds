#include <weapon.h>
inherit SWORD;

void create()
{
set_name("���C",({"long sword","sword"}));
set("long","�@��H�K��y���C�A���L�L���W�Q�{�ץi�O���U���C\n");
set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",800);
set("material","iron");
        }
init_sword(15);
         setup();
}


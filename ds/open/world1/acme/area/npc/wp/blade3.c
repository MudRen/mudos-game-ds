#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�j�M",({"big blade","blade"}));
set("long","�o�O�@��Z�L���H�`�ΨӨ������j�M�C\n");
set_weight(5000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1600);
set("volume",5);
set("material","iron");
        }
init_blade(27);
        setup();
}

#include <weapon.h>
inherit DAGGER;

void create()
{
set_name("�P��",({"dagger"}));
set("long","�o�O�@��M�`�H�Ҩرa�Ө����Ϊ��P���C\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",400);
set("material","iron");
        }
init_dagger(8);
        setup();
}
int query_autoload() { return 1;} // save eq by alick

#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()
{
set_name("[1;36m�y�M[0m",({"hunt blade","blade"}));
set_weight(36400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("long","�o�O�@��W�Q�L�񪺪��M,�`�Ψӥ��y�Ϊ�\n");
set("value",4368);
set("blade",52);
set("material","iron");
        }

init_blade(728);
setup();
}

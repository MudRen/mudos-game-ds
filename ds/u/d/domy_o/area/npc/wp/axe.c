#include <weapon.h>
inherit AXE;

void create()
{
set_name("����",({"axe"}));
set("long","�o�O�@��V�V�F�[�`�Ϊ��p���Y�C\n");
set_weight(8000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1500);
set("material","iron");
        }
init_axe(15);
        setup();
}


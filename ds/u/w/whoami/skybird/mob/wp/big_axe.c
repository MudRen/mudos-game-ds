#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name("����",({"big axe","axe"}));
        set("long","�o�O�@��j���L�b�A�O�q�n���j�~��ϥαo����C\n");
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",3);
        set("material","iron");
        set("unit", "��");
        set("value",6500);
        set("limit_str",60);
        }
        init_axe(60, TWO_HANDED);
        setup();
}


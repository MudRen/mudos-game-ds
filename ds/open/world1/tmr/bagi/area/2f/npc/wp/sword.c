#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("��C",({"big sword","sword"}));
        set("long","�o�O�@��j���L�b�A�O�q�n���j�~��ϥαo����C\n");
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",3);
                set("material","iron");
                set("unit", "��");
               set("value",1500);
                set("limit_str",15);
        }
        init_sword(30);
        setup();
}


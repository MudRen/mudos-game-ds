#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIC"�ѼC"NOR, ({ "sky sword","sword"} ) );
        set_weight(6000);
                set_default_object(__FILE__);
        else {
                set("volume",2);
        set("material","diamond");
                set("long", "�o�O�@��j���Ϊ��C�C\n");
                set("value", 1000);
        }
        init_sword(100);
        setup();
}

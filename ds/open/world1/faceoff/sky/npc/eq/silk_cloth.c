#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"��������"NOR, ({ "silk cloth","cloth"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@��Ѥ�������´������A, �ݰ_�Ӭ۷����K....\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/shield",2);
        set("armor_prop/dex",2);
                set("armor_prop/armor", 12);
              set("wear_msg",HIW"$N��W�F��������.\n"NOR);
        }
        setup();
}


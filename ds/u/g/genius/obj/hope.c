#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIW"�Ʊ椧�p"NOR, ({ "hope diamond","hope","diamond" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("long",HIW"\n�o�O�@��²��o�S���R���Ʊ澮�E�Ӧ����p�١C\n"NOR);
                set("unit", "�u");
                set("value",0);
                set("material","diamond");
        }
        set("armor_prop/int",1);
        set("armor_prop/armor",1);
        set("armor_prop/shield",1);
        setup();
}

int query_autoload() { return 1; }


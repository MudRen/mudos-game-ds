#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIR"�t��"HIW"�j���G"NOR,({ "christmas beard","beard" }) );
        set("long",@LONG
�o�O�@���զ⪺�j�G�l�A�����D������A�A�N�O�Q�n���W���C 
LONG);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","��");
        set("value",1);
        }
        set("armor_prop/armor",1);
        setup();
}


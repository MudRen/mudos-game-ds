#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(GRN"���]����"NOR ,({ "black helm" , "helm"  }) );
        set("long","�o�O�@�Ӭ۷�p�����`�¦��]���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "helmet");
        set("unit", "��" );
         set("value",60);
set("armor_prop/armor",10);
        }
        setup();
} 

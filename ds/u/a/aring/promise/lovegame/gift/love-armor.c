//2003�~10.10��y��g���C�i���H�`§��
//by Promise@DS

#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name(HIM"�C�i "HIC"�Z"NOR,({ "love armor","armor" }) );
        set("long",HIC"\n\t�褸2003�~�C�i���H�`§���C\n"NOR);
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",5);
         set("material","golden");
         set("unit", "��" );
         set("no_sell",1);
         }
        set("armor_prop/armor", 20);
        setup();
}

int query_autoload() { return 1; }


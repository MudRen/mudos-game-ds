#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name( GRN "�`��־c"  NOR ,({ "deep green shoes" , "shoes" }) );
        set("long","�o�O�@�������D����ְ����`���־c�C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,1);
                set("material","gold");
             }
                set("armor_prop/armor", 6);
                set("armor_prop/shield", 4);
                set("armor_prop/dodge", 20);
                set("armor_prop/dex",5);
        setup();
}

int query_autoload() { return 1; }


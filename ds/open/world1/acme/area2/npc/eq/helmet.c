#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("�@�n�Y��" ,({ "zhi lung helmet","helmet" }) );
        set("long","�o�O�@������j�{���Y���A���ᬰ�I���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(12000);
        set("material", "iron");
        set("unit", "��" );
       set("value",2000);
                set("volume",3);
        }
        set("limit_str",8);
          set("limit_con",20);
     set("armor_prop/armor",9);
        set("armor_prop/int",3);
         set("armor_prop/dex",-1);
        setup();
}


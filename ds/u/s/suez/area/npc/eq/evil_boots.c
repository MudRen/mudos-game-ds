
#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("����u" ,({ "evil boots","boots" }) );
        set("long","�o�O�@�����q�����u�A���O�W���g�V�F���֨���C\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "��" );
        set("value",1500);
        }
         set("armor_prop/armor", 5);
       set("armor_prop/shield", 2);
         set("armor_prop/dodge", 5);
        setup();
}
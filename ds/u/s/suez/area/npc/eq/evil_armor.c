
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("����ԥ�" ,({ "evil armor","armor" }) );
        set("long","�@�󴶳q���ԥҡA���O�g�V�F���֨���C\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "steel");
        set("unit", "��" );
        set("value",3000);
        }
set("armor_prop/armor",20);
set("armor_prop/shield", 2);
        setup();
}
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR"�_���Y�y"NOR ,({ "gem kerchief","kerchief" }) );
        set("long","�@�����⪺�����A�W���^�F�X���_�ۡA�ݰ_�ӤQ�������ɼڡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("value",4000);
                set("volume",2);
                set("armor_prop/armor", 10);
                set("armor_prop/int", 2);
                        }
        setup();
}


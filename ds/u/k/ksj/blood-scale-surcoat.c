#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(HIR"�K��"NOR""RED"�����"HIR"(S)"NOR,({ "blood-scale surcoat","surcoat" }) );
        set("long", @LONG
�@�������ܭ��A�ܭ��H������´���A�W����O���Q�諸����A���
�ܭ��U�N�۲H�H�����V�C
LONG
        );
        if ( clonep() )
                set_default_object(__FILE__);
        else {
         set_weight(1500);
         set("material", "leather");
         set("unit", "��" );
         set("value",20000);
         set("volume",3);
        }
        set("armor_prop/armor", 17);
        set("armor_prop/shield", 2);
        setup();
}

int query_autoload() { return 1; }

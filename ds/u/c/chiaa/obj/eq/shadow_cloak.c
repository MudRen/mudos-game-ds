//u/c/chiaa/obj/eq/shadow_cloak.c
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(WHT"�ۼv"BLU"�ܭ�"NOR,({"shadow cloak","cloak"}) );
   set("long","�@��ܻ��������ܭ�.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5555);
                set("material", "gauze");  //����
                set("unit", "��");                          
                set("armor_prop/armor", 15);
                set("armor_prop/shield",6);
                set("value",300);
        }
        setup();
}

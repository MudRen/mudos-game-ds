#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"���l�y�����t��"NOR, ({ "Gemini armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o��N�O���D�Q�G�c���ĤT�c�����l�y�t��\n");
                set("unit", "��");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",3);
                set("armor_prop/dex",1);
                set("armor_prop/int",10);
                set("armor_prop/str",3);
                set("armor_prop/dodge",10);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 45);
                set("armor_prop/wit",15);
                set("armor_prop/sou",10);
                set("wear_msg","$N��W$n,$N�P�즳�@�ѯ��O�]���$N!");
                set("remove_msg","$N���U�F$n,�A�����O�����F");
        }
        setup();
}
int query_autoload() { return 1; }

#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name(CYN"���]��"HIR"(S)"NOR,({"dark gloves","gloves"}) );
        set("long",@LONG
���æb�շt���a�����]�A�Ψ�����s�����֤�M�A���M���ݦ����m��
�O�����C
LONG
);
        set_weight(600); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",2500);          
                set("volume", 2);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",9);       
        setup();
}

int query_autoload() { return 1; }

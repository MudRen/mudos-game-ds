#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIW"�j��"HIG"�P�ҧ�"HIR"(S)"NOR,({"refractile ring","ring"}) );
        set("long",@LONG
�^�O�T��������ȧ١A���g���u���ĤH���������ͻ~�t�C
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",30);
                set("unit", "�u");       
                set("value",30000);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("armor_prop/armor",5);       
        setup();
}

int query_autoload() { return 1; }

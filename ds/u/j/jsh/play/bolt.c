#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIY"��"HIC"��"HIW"��"HIR"�b"NOR,({"yellow blue-bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�ѳy�b�W�K, �����һs, ���b���ˤO�j, ��w�L��.\n");
        }
set("value", 10000);
set_weight(3000);
set("amount",30);                
set("bullet/damage",80);        
set("bullet/unit","��");        
set("bullet/name",HIY"��"HIC"��"HIW"��"HIR"�b"NOR);      
set("type","small");            
setup();
}


#include <armor.h>
inherit NECK;
void create()
{
        set_name("���B��", ({"lucky necklace","necklace","lucky" }) );
        set("long", @LONG
�@�Ӷ�ꪺ���Y�Τ@����l��F�_�ӡA���Y�̭��٦��@�ө��Ϊ����A�C
LONG);
    set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��" );
        set("armor_prop/armor", 1);
        set("armor_prop/dex",2); 
        set("armor_prop/str",-1);
        set("armor_prop/con",-1);        set("armor_prop/bar",1);
        set("value", 800);
        }
        setup();
}

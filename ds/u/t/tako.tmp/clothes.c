#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�ʥ��­m",({"grass clothes","clothes"}) );
        set("long",@LONG
�o�O�@��¥��s´�Ӧ����B�ʭm�A�i�H����B�ʮɤ@�ǻ��L����
�ˡC
[SAVE-EQ]

LONG
);
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("value",240);
    set("armor_prop/armor",70); 
    set("armor_prop/dodge",70);
    set("armor_prop/unarmed",70);
    set("armor_prop/da-fork",80);
    set("armor_prop/bagi_fist",40);
    set("armor_prop/force",70) ;
    set("armor_prop/horse-steps",70);       
 setup();
}
 int query_autoload() { return 1; }


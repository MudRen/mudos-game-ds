#include <armor.h>
inherit WRISTS;

void create()
{
set_name("���@�u",({"green arms","arms"}) );
set("long","�o�O�H�ժ��һs�Ӧ����@�u,��b�Ӧ����A�C\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("material", "steel");
set("value",1800);
//set("armor_prop/armor",30);
set("limit_lv",55);
 }
setup();
}

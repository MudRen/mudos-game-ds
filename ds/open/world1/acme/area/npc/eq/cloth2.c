#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("���l�ŭm" ,({ "plume cloth","cloth" }) );
        set("long","�o�O�@�󻴬X����A�A�b���ݦ��ӦФ�˹��A�����m�O�t�C\n");
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "��" );
          set("value",600);
        }
          set("armor_prop/armor", 5);
        setup();
}

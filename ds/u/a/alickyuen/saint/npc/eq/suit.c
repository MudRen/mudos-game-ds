#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�򨭦�",({"suit"}) );
        set("long","�o�O�@��ܴ��q����A�A��W��|�۰ʦ����A�㦳�ܦn�����m�O�C\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
set("value",1000);
set("material","cloth");
set("armor_prop/armor", 10);
        }
        setup();
}

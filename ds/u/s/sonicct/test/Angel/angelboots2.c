#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name(HIR"�ѨϪ��u"NOR, ({ "Angel boots","boots" }) );
set("long",
"�o�O"HIR"�Ѩ�"NOR"�����u�C\n"
);
set_weight(2000);
if(clonep() )
set_default_object(__FILE__);
else
{
 set("unit", "��");
set("armor_prop/armor", 30);
        }
}

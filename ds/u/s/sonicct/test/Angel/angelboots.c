#include <ansi.h>
#include <armor.h>
inherit BOOTS;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"�ѨϪ��u"NOR, ({ "Angel boots","boots" }) );
set("long",
"�o�O"HIR"�Ѩ�"NOR"�����u�C\n"
);
        set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("armor_prop/armor", 50);
                set("armor_prop/dex",10);
        }
 set("replica_ob","/u/s/sonicct/test/Angel/angelboots2.c");
}

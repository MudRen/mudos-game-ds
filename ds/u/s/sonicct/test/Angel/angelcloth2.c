#include <ansi.h>
#include <armor.h>
inherit CLOTH;
 void create()
{
        set_name(HIR"�ѨϦЦ�"NOR,({"angel cloth","cloth"}) );
        set("long",@long
�o�O"HIR"�Ѩ�"NOR"����A�C
long
);
         set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value",1000);
                set("limit_str",100);
                 set("armor_prop/armor",30);
        }
        setup();
 }

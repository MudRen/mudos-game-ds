#include <ansi.h>
#include <armor.h>
inherit PANTS;
inherit F_UNIQUE;
void create()
{
set_name(HIR"�ѨϪ���"NOR,({"angel skirt","skirt"}) );
        set("long",
"�o�O"HIR"�Ѩ�"NOR"�����ȡC\n"
);
set_weight(2000);
 if(clonep() )
        set_default_object(__FILE__);
         else
         {
                 set("unit", "��");
                 set("value",1000000);
set("limit_con",100);
                 set("armor_prop/armor",30);
         }
        setup();
 }
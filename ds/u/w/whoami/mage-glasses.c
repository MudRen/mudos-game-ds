#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIW"�]�N�v����"NOR,({"mage glasses","glasses"}) );
        set("long",@long
�]�N�v���W������A�ݰ_�Ӧ��G�O�W�P���C
long
);
        set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
else
{
                set("volume",1);
                set("unit", "��");
                set("value",5000);
        }
                set("limit_lv",30);
                set("armor_prop/int",1);
                set("armor_prop/armor",1);
                set("armor_prop/bio",1);
                set("armor_prop/bar",-1);
                set("armor_prop/tec",-1);
                set("armor_prop/show_damage",1);
        setup();
} 

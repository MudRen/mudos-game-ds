#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIW"�Q��t�]"NOR,({"ten holy pearl","pearl"}) );
        set("long","�@�������۾԰�C�������ͥ\\�O�����_�]�l�C\n");
      set_weight(1200);
        set("unit","��");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",8000);
                set("material","silver");
                set("armor_prop/armor", 6);
                set("armor_prop/dodge", 10);
                set("armor_prop/dex", 2);
        set("armor_prop/show_damage",1);
        }
        setup();
}
void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

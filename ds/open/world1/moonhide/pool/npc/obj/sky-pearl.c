#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIB"����"HIW"�F�]"NOR,({"sky pearl","pearl"}) );
        set("long","�b���Ѥs�W�A�l���F�C�C�|�Q�E�Ѫ����O�ҥ��y���]�l�C\n");
      set_weight(200);
        set("unit","��");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",3000);
                set("material","silver");
                set("limit_lv", 15);
                set("limit_str", 30);
             }
                set("armor_prop/armor", 10);
                set("armor_prop/str", 2);
                set("armor_prop/int", 1);
                set("armor_prop/shield", 10);
                set("armor_prop/sou", 1);
                set("armor_prop/tec", -1);
        setup();
}


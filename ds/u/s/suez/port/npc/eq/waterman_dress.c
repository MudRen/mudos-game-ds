#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"����A"NOR,({"waterman dress","dress"}) );

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
         set("long","���x��[�W�g�A��...�o...�o���D�O�ǻ���������A�I�I\n"
                 HIW"�u�Q��W�j��:�u�ڭn�N����G���g�@�A�I��������v\n"NOR
          );
         set("material", "cloth");
         set("unit", "��");
         set("value",500);

         set("armor_prop/armor", 1);

        }
        setup();
	set("wear_msg",HIY"$N"HIY"��_�@��$n"HIY"�A�\\�F��POSE�j�ۡR�u�ڭn�N����G���g�@�A�I��������v\n"NOR);
}



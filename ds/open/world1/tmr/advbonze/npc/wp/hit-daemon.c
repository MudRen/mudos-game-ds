#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( HIY "�p�Ӿ��]��"  NOR ,({"hit-daemon staff","staff"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "��");
               set("long",@LONG
�o�O�@��ΤW�n����۩һs���������A����Ф������]���_�A�ǻD�㦳���q�O�A
�Ω�h�����]�A�S�O���\�ġC
LONG
);
               set("volume",6);
               set("value",12000);
               set("material", "gold");
               set("limit_str",40);
               set("limit_int",25);
               set("limit_con",30);
        }
      init_staff(60);
      set("weapon_prop/dex",  1);
      set("weapon_prop/int",  1);
      set("male_only",1);
      setup();
}


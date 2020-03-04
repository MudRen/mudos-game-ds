#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"七七嬰杖"NOR,({"seven staff","staff","_SEVEN_STAFF_"}));
set("long",
  "一把令正道聞之氣奪的魔杖，此杖為利用無辜嬰孩提煉而成，卻仍活生。\n"
"生不得轉生投胎，看著杖上蠕動的血腥嬰頭，你不禁為之心寒。\n"
);
        set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "把");
            set("value",3000);
		set("volume",4);
          set("limit_str",30);
        }
        set("weapon_prop/int",2);
init_staff(40);
        setup();
} 


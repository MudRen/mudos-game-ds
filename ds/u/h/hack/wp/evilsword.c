#include <weapon.h>
inherit SWORD;

void create()
{
set_name("辟邪劍",({"ward off evils sword","sword"}));
set("long",
           "這把劍比長劍短些，又比短劍長些，外型特異，在劍柄處"
           "有著二個古錢穿過，且垂掛著一個吉祥結。",
     );
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1000);
set("volume",3);
        }
init_sword(15);
set("weapon_prop/hit",8);
         setup();
} 

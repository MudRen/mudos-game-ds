/* write by -Acme-
*/

#include <ansi2.h>
#include <weapon.h>
inherit STAFF;

void create()
{

    switch( random(3) ) {
        case 0:
            set_name(GRN"魔氣杖"NOR,({ "fiend kee staff" ,"staff" }) );
            set("long", "一把青綠色散發著魔氣的長杖。");
            set_weight(3500);
            set("value", random(4000)+1);
            set("volume",3);
            init_staff(random(11)+40);
            break;
        case 1:
            set_name(GRN"妖氣杖"NOR,({ "evil kee staff" ,"staff" }) );
            set("long", "一把青綠色散發著妖氣的長杖。");
            set_weight(3000);
            set("value", random(3000)+1);
            set("volume",3);
            init_staff(random(11)+30);
            break;
        default:
            set_name(GRN"鬼氣杖"NOR,({ "ghost kee staff" ,"staff" }) );
            set("long", "一把青綠色散發著鬼氣的長杖。");
            set_weight(2000);
            set("value", random(2000)+1);
            set("volume",3);
            init_staff(random(11)+20);
            break;
    }

    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("material", "iron");
    }

    switch( random(100) ) {
        case 0..19: set("weapon_prop/str",1); break;
        case 20..39: set("weapon_prop/con",1); break;
        case 40..59: set("weapon_prop/int",1); break;
        case 60..79: set("weapon_prop/dex",1); break;
        case 99:
            set("weapon_prop/str", 1);
            set("weapon_prop/con", 1);
            set("weapon_prop/int", 1);
            set("weapon_prop/dex", 1);
            break;
    }

    setup();
}

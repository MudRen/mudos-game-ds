/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit SHIELD;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"破神盾"NOR ,({ "po god shield", "shield" }) );
            set("long","一件來自鬼界的盾，灰色的神秘配備。\n");
            set_weight(9000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+15);
            break;
        case 21..45:
            set_name(HBK"困心盾"NOR ,({ "heart shield", "shield" }) );
            set("long","一件緊緊束住手掌的盾。\n");
            set_weight(8000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+10);
            break;
        case 46..70:
            set_name(HBK"歸西盾"NOR ,({ "west shield", "shield" }) );
            set("long","一件用怪異材質製成的輕質盾。\n");
            set_weight(4000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(10)+5);
            break;
        default:
            set_name(HBK"戰魂盾"NOR ,({ "ghost shield", "shield" }) );
            set("long","一件來自妖界的盾，似乎存著許\多怨靈。\n");
            set_weight(6000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+5);
            break;
    }

    switch( random(100) ) {
        case 0..19: set("armor_prop/str",1); break;
        case 20..39: set("armor_prop/con",1); break;
        case 40..59: set("armor_prop/int",1); break;
        case 60..79: set("armor_prop/dex",1); break;
        case 99:
            set("armor_prop/str", 1);
            set("armor_prop/con", 1);
            set("armor_prop/int", 1);
            set("armor_prop/dex", 1);
            break;
    }

    if ( clonep() )
        set_default_object(__FILE__);
    else {
        set("material", "iron");
        set("unit", "面" );
    }

    setup();
}

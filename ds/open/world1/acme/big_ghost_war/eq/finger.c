/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit FINGER;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"破神戒"NOR ,({ "po god ring", "ring" }) );
            set("long","一件來自鬼界的戒指，灰色的神秘配備。\n");
            set_weight(3000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(2)+3);
            break;
        case 21..45:
            set_name(HBK"困心戒"NOR ,({ "heart ring", "ring" }) );
            set("long","一件緊緊束住手指頭的戒指。\n");
            set_weight(2000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(2)+2);
            break;
        case 46..70:
            set_name(HBK"歸西戒"NOR ,({ "west ring", "ring" }) );
            set("long","一件用怪異材質製成的輕質戒指。\n");
            set_weight(1000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(2)+1);
            break;
        default:
            set_name(HBK"戰魂戒"NOR ,({ "ghost ring", "ring" }) );
            set("long","一件來自妖界的戒子，似乎存著許\多怨靈。\n");
            set_weight(1500);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", 1);
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
        set("unit", "只" );
    }

    setup();
}

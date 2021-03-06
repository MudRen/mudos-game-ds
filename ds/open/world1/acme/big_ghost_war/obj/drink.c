/* write by -Acme-
*/

inherit ITEM;
inherit F_WATER;

void create()
{
    switch( random(3) ) {
        case 0:
            set_name("魔氣酒", ({ "fiend kee wine", "wine" }) );
            set("long", "一個發著紅色泡泡帶著煙霧的紅酒。");
            set("value", 1500);    
            set("heal_hp", random(200)+1);
            set("heal_ap", random(200)+1);
            set("heal_mp", random(200)+1);
            break;
        case 1:
            set_name("妖氣湯", ({ "evil kee broth", "broth" }) );
            set("long", "一個發著紫色泡泡帶著煙霧的紫湯。");
            set("value", 1300);    
            set("heal_hp", random(150)+1);
            set("heal_ap", random(150)+1);
            set("heal_mp", random(150)+1);
            break;
        default:
            set_name("鬼氣水", ({ "ghost kee water", "water" }) );
            set("long", "一個發著泡泡帶著煙霧的白色水。");
            set("value", 1000);    
            set("heal_hp", random(100)+1);
            set("heal_ap", random(100)+1);
            set("heal_mp", random(100)+1);
            set("water_remaining", 3);
            break; 
    }
    set_weight(100);
    set("unit", "瓶");
    set("water_remaining", 3);
    setup();
}

/* write by -Acme-
*/

inherit ITEM;
inherit F_FOOD;

void create()
{
    switch( random(5) ) {
        case 0:
            set_name("凝厭丹", ({ "all pill", "pill" }) );
            set("long", "一顆發著惡臭的星狀且呈黑色之怪丹。\n");
            set("value", random(2000)+1);  
            set("heal_hp", random(500)+1);
            set("heal_ap", random(500)+1);
            set("heal_mp", random(500)+1);
            break;
        case 1:
            set_name("匯氣丹", ({ "ap pill", "pill" }) );
            set("long", "一顆長形的黃色小丹藥。\n");
            set("value", random(2000)+1);  
            set("heal_ap", random(500)+1);
            break;
        case 2:
            set_name("集神丹", ({ "mp pill", "pill" }) );
            set("long", "一顆紅色的中空呈戒狀的小丹藥。\n");
            set("value", random(2000)+1);  
            set("heal_mp", random(500)+1);
            break;
        default:
            set_name("聚命丹", ({ "hp pill", "pill" }) );
            set("long", "一顆藍色的三角形小丹藥。\n");
            set("value", random(2000)+1);  
            set("heal_hp", random(500)+1);
            break;
    }

    set_weight(10);
    set("unit", "顆");
    set("food_remaining",1);
    setup();

}

/* write by -Acme-
*/

inherit ITEM;

void create()
{
     switch( random(100) ) {
         case 0..10:
             set_name("金球", ({ "gold ball", "ball" }) );
             set_weight(300);
             set("kind", "gold");
             set("power", random(10)+1);
             set("value", random(4000)+1);
             set("long", "一顆純金打造的小球，不知有何用途。");
             break;
         case 11..31:
             set_name("銀球", ({ "silver ball", "ball" }) );
             set_weight(250);
             set("kind", "silver");
             set("power", random(10)+1);
             set("value", random(3000)+1);
             set("long", "一顆純銀打造的小球，不知有何用途。");
             break;
         case 32..62:
             set_name("銅球", ({ "brass ball", "ball" }) );
             set_weight(200);
             set("kind", "brass");
             set("power", random(10)+1);
             set("value", random(2000)+1);
             set("long", "一顆純銅打造的小球，不知有何用途。");
             break;
         default:
             set_name("鐵球", ({ "iron ball", "ball" }) );
             set_weight(100);
             set("kind", "iron");
             set("power", random(10)+1);
             set("value", random(1000)+1);
             set("long", "一顆純鐵打造的小球，不知有何用途。");
             break;
     }

     set("unit", "顆");
     setup();
}

#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create ()
{
   set_name("香包", ({ "fragrant bag", "bag" })); 
   set("long", @LONG
香包是一種吉祥的避邪物，用各種顏色的綢布做成囊狀，裡面放置香
料，便是香包。以前縫製香包是一項很重要的女紅，年輕的女孩子都
要會縫。現在不論是商店或街上都能看到各種不同造型的香包在販賣
，每逢端午，各地都可見民眾在販賣香包的攤位上選購各式香包，都
令人愛不釋手。
LONG);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "個" );
      set("armor_prop/armor", 1);
      set("value", 100);
   }
   setup ();
}


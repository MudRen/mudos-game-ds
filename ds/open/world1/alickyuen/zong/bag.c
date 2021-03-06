#include <armor.h>
#include <ansi2.h>

inherit WAIST;

void create ()
{
   set_name(HIY"香包"NOR, ({ "fragrant bag", "bag" })); 
   set("long", @LONG
香包是一種吉祥的避邪物，用各種顏色的綢布做成囊狀，裡面放置香
料，便是香包。以前縫製香包是一項很重要的女紅，年輕的女孩子都
要會縫。現在不論是商店或街上都能看到各種不同造型的香包在販賣
，每逢端午，各地都可見民眾在販賣香包的攤位上選購各式香包，都
令人愛不釋手。

-2008 年端午節獎品 By Alickyuen@DS
LONG);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "個" );
      set("armor_prop/armor", 15);
      set("armor_prop/shield", 15);
      set("value", 0);
   }
   setup ();

   call_out("heal", 60);
}

int query_autoload () { return 1; }

void heal ()
{
   object me = environment(this_object());

   if( !this_object() || !me ) return;

   if( interactive(me) && me->query_temp("armor/waist") == this_object())
   {
      if( me->query("hp") < me->query("max_hp") )
      {
         me->add("hp", random(50));
         tell_object(me, YEL"香包散發出的香味令你突然感到體力有所恢復。\n"NOR);
      }
      if( me->query("mp") < me->query("max_mp") )
      {
         me->add("mp", random(50));
         tell_object(me, YEL"香包散發出的香味令你突然感到法力有所恢復。\n"NOR);
      }
      if( me->query("ap") < me->query("max_ap") )
      {
         me->add("ap", random(50));
         tell_object(me, YEL"香包散發出的香味令你突然感到內勁有所恢復。\n"NOR);
      }
   }
   call_out("heal", random(60));
}

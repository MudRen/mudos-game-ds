#include <ansi.h>
inherit NPC;
void create()
{
  set_name("申子平", ({ "shen tsiping","Shen","shen","Tsiping","tsiping" }) );
  set("gender", "男性" );
  set("long",@LONG
他一襲素淨長衣在此坐著，臉上帶著一絲倦意。一杯接著一杯的啜飲
著。只看他不發一言，望著朝天樓的方向，靜靜的發呆。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
  carry_object(__DIR__"armor/02")->wear();
}
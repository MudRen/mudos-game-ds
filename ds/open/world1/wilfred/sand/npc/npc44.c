// 這也算恐怖的 mob 之一, 比點液還強許多
// 他身上帶了一個限制行動的物件, 以防玩家用神令符 hest 他去打青眼白龍
// wilfred@DS  :Q~~~~~~

#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIR"真紅眼"HIW""BLK"黑龍"NOR,({"red-eye black dragon","dragon"}) );
  set("long",
HIR"\n火紅的雙眼，漆黑的身軀，張牙舞爪，似乎在訴說著牠的憤怒\n"
HIR"\n對於眼前的一切，牠似乎只存在著一個念頭\n"
HIR"\n\t\t全部毀滅\n\n"NOR
);
  set("race", "dragon");
  set("unit","隻");
  set("age",500);
  set("level",60);
  set("attitude", "heroism");
  set("limbs", ({ "頭部", "腹部","胸部","巨爪","巨尾","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  set("addition_armor",80);
  set("addition_damage",80);
  set("Merits/wit",3);
  set("Merits/bar",9);
  set("Merits/bio",5);
  add("apply/hit",50);
  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"wp/wp9")->wield();
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }
   ob->add_temp("hero",3);
   ob->add("popularity",3);
   tell_object(ob,HIC"[你得到額外的 3 點聲望!!]\n"NOR);
   ::die();
   return;
}


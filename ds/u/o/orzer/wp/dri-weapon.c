#include <ansi.h>
#include <weapon.h>
inherit SWORD;
mapping chwps = ([
        "blade":                "刀",
        "sword":                "劍",
        "claw":                 "爪",
        "fist":                 "爪",
        "axe":                  "斧",
        "staff":                "杖",
        "fork":                 "槍",
        "dagger":               "匕首",
        "hammer":               "鎚",
        "whip":                 "鞭",
]);

void create()
{
  set_name("御"HIC"星"NOR"劍"NOR , ({ "dri-star sword","sword" }) ); 
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "御星劍，一把很儉樸的劍，在手炳處有著五星裝飾\n"
                "，渾身散發出一股沖天霸意。\n"
                "<   可以使用chwp [型態]　轉換成不同武器>\n"
    );
    set("material", "gold");
    set("value",50);
  }
  set("weapon_prop/str",20);
  set("weapon_prop/con",20);
  set("weapon_prop/dex",20);
  set("weapon_prop/int",20);  
  set("weapon_prop/bar",3);
  set("weapon_prop/wit",3);
  set("weapon_prop/tec",3);
  set("weapon_prop/dodge",30);
  set("wield_msg",HIW"$N抽出$n，瞬間週遭湧起陣陣霸氣逼人！\n"NOR);
  set("unwield_msg",HIW"$N放下$n，瞬間週遭的刺人霸氣緩緩散去！\n"NOR);
  init_sword(75+random(15)); 
  setup();
}
int query_autoload() { return 1; }
void init()
{
    add_action("do_chwp","chwp");
}

int do_chwp(string str)
{ 
   object ob = this_object(),me=this_player();
   string *wpty=keys(chwps),wtys;   
   if( ob->query("equipped") )
                         return notify_fail("請先解除裝備。\n"); 
   if(!str) return notify_fail("chwp [型態]。\n");
   if(member_array(str,wpty) == -1 )
                      return notify_fail("沒有這種轉換型態。\n");
   ob->set("skill_type",str);
   wtys=chwps[str];
   message_vision(
   "$N手中氣勁大作，"HIG"一陣耀眼的"HIY"光芒"NOR"閃過，手中的$n變成了"HIR+wtys+NOR"型態。\n"
   ,me,ob);
   ob->set_name("御"HIC"星"NOR+wtys,({"dri-star "+str,str}));
   ob->set("long", "御星"+wtys+"，一把很儉樸的"+wtys+"，在手炳處有著五星裝飾\n"
                   "，渾身散發出一股沖天霸意。\n"
                   "<   可以使用chwp [型態]　轉換成不同武器>\n"
   );
return 1;
}     

 


#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIM"聖誕"HIW"泡泡"HIR"襪"NOR ,({ "xmas popo sock","sock" }) );
      set("long", @LONG
2003年聖誕節紀念EQ。
LONG
);
           set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "雙" );
                //set("value",100000);
                set("valme",1);
                set("no_sac",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_auc",1);
                set("armor_prop/armor", 3);
                set("armor_prop/int",1);
                set("armor_prop/con",1); 
                set("armor_prop/str",1);
                set("armor_prop/dex",1);    
                set("wear_msg",HIR"$N穿上了一雙$n"HIR"後，便跟大家說"HIM"Ｍｅｒｒｙ　"HIW"Ｃｈｒｉｓｔｍａｓ"HIR"∼∼\n"NOR);
                set("unequip_msg",HIY"$N"HIY"脫下了$n"HIY"後，感覺沒這麼有"HIR"聖誕氣息"HIY"！！\n"NOR);  
  }

        setup();
}


int query_autoload() { return 1; }


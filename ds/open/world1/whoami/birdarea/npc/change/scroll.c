#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"《防具》"HIB"加強捲軸"NOR, ({ "equip scroll" , "scroll"}) );
        set_temp("eq_scroll",1);
        set_weight(250); 
        set("needaward",200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  
"這個藍色的捲軸上面寫滿了密密麻麻的文字，這些文字似乎不屬\n"
"於這個空間，看得你是滿頭的霧水，看來只好問問神了•\n"+
HIC"(help scroll)\n"NOR);
                set("unit", "張");
                set("value", 0);
        }
        setup();
}

void init()
{ 
        add_action("do_casteq", "casteq"); 
        add_action("do_help","help");
}


int do_help(string str)
{
  if(!str || str != "scroll") return 0;
  write(HIG"\n\t◎用法: casteq <id>\n"NOR);
  return 1;
}
int do_casteq(string arg)
{
        object me = this_player(), ob;
        int add = 1+random(2); 
        int add1 = 1+random(30);
        int add2 = 1+random(10);
        int add3 = 1+random(5);
        if( !arg ) return notify_fail("casteq <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("armor_type") )
                return notify_fail("只能使用在防具上面。\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("這個防具已經不能再升級了。\n");
        if( ob->query("equipped") )
                return notify_fail("請先解除裝備。\n");
      switch( random(100) ){
   case 0..1:
        switch(random(100)){
        case 1..5:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bar", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了獸性(BAR) "+add+" 點了•\n");
         break;
        case 6..10: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/wit", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了魔法(WIT) "+add+" 點了•\n");
         break;
        case 11..15:    
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bio", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了生物(BIO) "+add+" 點了•\n");
         break;
        case 16..20: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/tec", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了科技(TEC) "+add+" 點了•\n");
         break;
        case 21..25: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/sou", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了心靈(SOU) "+add+" 點了•\n");
         break;
        case 26..35:  
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/armor", add1); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了物理防禦力 "+add1+" 點了•\n");
         break;
        case 36..45: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/shield", add1); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了心靈抵抗力 "+add1+" 點了•\n");
         break;
        case 46..55: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/damage", add2); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了物理攻擊力 "+add2+" 點了•\n");
         break;
        case 56..65: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/con", add3); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了體質(CON) "+add3+" 點了•\n");
         break;
        case 66..75:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/str", add3); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了力量(STR) "+add3+" 點了•\n");
         break; 
        case 76..85:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/int", add3); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了智慧(INT) "+add3+" 點了•\n");
         break;
        case 86..95:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/dex", add3); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了敏捷(DEX) "+add3+" 點了•\n");
         break;
        default:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/dodge", add2); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了閃躲迴避率 "+add2+"% 了•\n");
         break;
        }        message_vision("$N身上的"+ob->query("name")+"閃出"HIY"金黃色的光芒"NOR"，在光芒退去後，"+ob->query("name")+"似乎變的更強了。\n", me);
        destruct(this_object());
      break;
     default:
message_vision(
"$N身上的"+ob->query("name")+"發出一聲巨響，原來是施咒錯誤把"
+ob->query("name")+"給搞壞了，$N也順手丟了這個廢物•\n",me);
    destruct(ob);
     break;
    }
          return 1;
}


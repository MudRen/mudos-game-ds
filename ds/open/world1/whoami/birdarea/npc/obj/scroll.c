#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(16)){
        case 0..14:
        set_name(HIW"《防具》"HIB"加強捲軸"NOR, ({ "equip scroll" , "scroll"}) );
        set_temp("eq_scroll",1);
        break;
        default:        
        set_temp("wp_scroll",1);
        set_name(HIW"《武器》"HIB"加強捲軸"NOR, ({ "weapon scroll", "scroll" }) );
        break;
        }
        set_weight(250);
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
   if ( query_temp("wp_scroll")){
        add_action("do_castwp", "castwp"); 
   } else {
        add_action("do_casteq", "casteq"); 
          } 
   add_action("do_help","help");
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        string name;
        int add  = 1+random(2),add1 = 1+random(5),add2 = 1+random(5),add3 = 1+random(2),x,y; 
        if( !arg ) return notify_fail("castwp <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("skill_type") ) return notify_fail("只能使用在武器上面。\n");
        if( ob->query_temp("lv_up") > 4 ) return notify_fail("這個武器已經不能再升級了。\n");
        if( ob->query("equipped") ) return notify_fail("請先解除裝備。\n"); 
        name = ob->query("name");
        if( ob->query_temp("lv_up") == 1) name = replace_string( name, "★", HIC"★"NOR );
        else if( ob->query_temp("lv_up") == 2) name = replace_string( name, "★", HIY"★"NOR );
        else if( ob->query_temp("lv_up") == 3) name = replace_string( name, "★", HIG"★"NOR );
        else if( ob->query_temp("lv_up") == 4) name = replace_string( name, "★", HIR"★"NOR );
        
        if( ob->query_temp("lv_up") < 2)  x = 0;
        if( ob->query_temp("lv_up") == 2) x = 2;
        if( ob->query_temp("lv_up") == 3) x = 4;        
        if( ob->query_temp("lv_up") == 4) x = 8;
        if( x > 2) y = 106;
        else y = 100;
        
   if( random(x) < 1 ) {
        switch(random(y)){
        case 0..19:    ob->add("weapon_prop/damage", add1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了物理攻擊力 "+add1+" 點了•\n");break; 
        case 20..29:   ob->add("weapon_prop/con", add3); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了體質(CON) "+add3+" 點了•\n"); break;
        case 30..39:   ob->add("weapon_prop/str", add3); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了力量(STR) "+add3+" 點了•\n"); break; 
        case 40..49:   ob->add("weapon_prop/int", add3); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了智慧(INT) "+add3+" 點了•\n"); break;
        case 50..59:   ob->add("weapon_prop/dex", add3); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了敏捷(DEX) "+add3+" 點了•\n"); break;
        default:       ob->add("weapon_prop/hit", add3); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了攻擊命中率 "+add3+"% 了•\n"); break;
        case 101:      ob->add("weapon_prop/bar", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了獸性(BAR) 1 點了•\n");        break;
        case 102:      ob->add("weapon_prop/wit", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了魔法(WIT) 1 點了•\n");        break;
        case 103:      ob->add("weapon_prop/tec", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了科技(TEC) 1 點了•\n");        break;
        case 104:      ob->add("weapon_prop/sou", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了心靈(SOU) 1 點了•\n");        break;
        case 105:      ob->add("weapon_prop/bio", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了生物(BIO) 1 點了•\n");        break;
        }
     message_vision("$N身上的"+ob->query("name")+"閃出"HIY"金黃色的光芒"NOR"，在光芒退去後，"+ob->query("name")+"似乎變的更強了。\n", me);
     ob->add_temp("lv_up",1);
     if( ob->query_temp("lv_up") == 1 ) ob->set("name",HIC"★"NOR+name);
     else ob->set("name", name);
     destruct(this_object());
   } else {
     message_vision("$N身上的"+ob->query("name")+"發出一聲巨響，原來是施咒錯誤把"+ob->query("name")+"給搞壞了，$N也順手丟了這個廢物•\n",me);
     destruct(ob); destruct(this_object());
   }
   return 1;
}

int do_casteq(string arg)
{
        object me = this_player(), ob;
        string name;
        int add = 1+random(2), add1 = 1+random(5), add2 = 1+random(5), add3 = 1+random(2),x,y;
        if( !arg ) return notify_fail("casteq <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("armor_type") ) return notify_fail("只能使用在防具上面。\n");
        if( ob->query_temp("lv_up") > 4 ) return notify_fail("這個防具已經不能再升級了。\n");
        if( ob->query("equipped") ) return notify_fail("請先解除裝備。\n");
        name = ob->query("name");
        if( ob->query_temp("lv_up") == 1) name = replace_string( name, "★", HIW"★"NOR );
        else if( ob->query_temp("lv_up") == 2) name = replace_string( name, "★", HIC"★"NOR );
        else if( ob->query_temp("lv_up") == 3) name = replace_string( name, "★", HIY"★"NOR );
        else if( ob->query_temp("lv_up") == 4) name = replace_string( name, "★", HIB"★"NOR );
        
        if( ob->query_temp("lv_up") < 2)  x = 0;
        if( ob->query_temp("lv_up") == 2) x = 2;
        if( ob->query_temp("lv_up") == 3) x = 4;        
        if( ob->query_temp("lv_up") == 4) x = 8;
        if( x > 2 ) y = 106;
        else y = 100;
        
    if( random(x) < 1 ){            
        switch(random(y)){
        case 0..14: ob->add("armor_prop/armor", add1); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了物理防禦力 "+add1+" 點了•\n");break;
        case 15..29: ob->add("armor_prop/shield", add1); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了心靈抵抗力 "+add1+" 點了•\n");break;
        case 30..44: ob->add("armor_prop/damage", add1); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了物理攻擊力 "+add1+" 點了•\n");break;
        case 45..54: ob->add("armor_prop/con", add3); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了體質(CON) "+add3+" 點了•\n"); break;
        case 55..64: ob->add("armor_prop/str", add3); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了力量(STR) "+add3+" 點了•\n"); break; 
        case 65..74: ob->add("armor_prop/int", add3); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了智慧(INT) "+add3+" 點了•\n"); break;
        case 75..84: ob->add("armor_prop/dex", add3); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了敏捷(DEX) "+add3+" 點了•\n"); break;
        default:     ob->add("armor_prop/dodge", add2); 
                     ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了閃躲迴避率 "+add2+"% 了•\n"); break;
        case 101:      ob->add("weapon_prop/bar", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了獸性(BAR) 1 點了•\n");        break;
        case 102:      ob->add("weapon_prop/wit", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了魔法(WIT) 1 點了•\n");        break;
        case 103:      ob->add("weapon_prop/tec", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了科技(TEC) 1 點了•\n");        break;
        case 104:      ob->add("weapon_prop/sou", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了心靈(SOU) 1 點了•\n");        break;
        case 105:      ob->add("weapon_prop/bio", 1); 
                       ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了生物(BIO) 1 點了•\n");        break;
        }
        message_vision("$N身上的"+ob->query("name")+"閃出"HIY"金黃色的光芒"NOR"，在光芒退去後，"+ob->query("name")+"似乎變的更強了。\n", me);
        ob->add_temp("lv_up",1);
        if( ob->query_temp("lv_up") == 1 ) ob->set("name",HIW"★"NOR+name);
        else ob->set("name", name);
        destruct(this_object());
    } else {
    message_vision("$N身上的"+ob->query("name")+"發出一聲巨響，原來是施咒錯誤把"+ob->query("name")+"給搞壞了，$N也順手丟了這個廢物•\n",me);
    destruct(ob); destruct(this_object()); 
    }
        return 1;
}

int do_help(string str)
{
  if(!str || str != "scroll") return 0; 
  if ( query_temp("wp_scroll")){
  write(HIG"\n\t◎用法: castwp <id>\n"NOR);
  } else {
  write(HIG"\n\t◎用法: casteq <id>\n"NOR);
  }
  return 1;
}

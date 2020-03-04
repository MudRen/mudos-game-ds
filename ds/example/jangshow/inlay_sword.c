// Jangshow@DS 暫離 LPC 界之作,原因要聯考 =_=a
// 寶石鑲嵌跟特攻可補充
// 一顆洞的 wp,兩顆以上的會寫範例
#include <ansi.h>
#include <weapon.h> 
#define WPNAME "鑲嵌之劍"
inherit SWORD;

//string *stone= ({"一道巨火！狂噴沖天！","

void create()
{
  set_name(HIY"鑲嵌之劍"NOR , ({ "inlay sword","sword" }) ); 
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "上面有一個小洞，不知道是幹麻的[inlay xxx]。\n");
    set("material", "gold");
    set("value",30000);
  }
  set("weapon_prop/bar",1);
  set("weapon_prop/wit",1);
  set("weapon_prop/tec",1);
  set("weapon_prop/dodge",10);
//  set("weapon_prop/sword",10);    
  init_sword(60); 
  setup();
}
void init()
{
     add_action("do_inlay","inlay");
}
int do_inlay(string arg)
{ 
    object me=this_player(),obj;  
    if(this_object()->query_temp("inlaied")==1) 
       return notify_fail("裡面已經鑲了一顆寶石，你沒看到嗎？\n");    

    /***************************************鑲嵌開始****************************************/ 

    if(!arg || arg !="red stone") return notify_fail("你要鑲嵌(inlay)什麼？\n"); 
              { 
               if(!objectp(obj=present("red stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIR"紅寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIR"紅寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIR"火系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/red",1);
                    } 
              }      
    if(!arg || arg !="blue stone") return notify_fail("你要鑲嵌(inlay)什麼？\n"); 
              { 
               if(!objectp(obj=present("blue stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"BLU"藍寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"BLU"藍寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："BLU"水系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/blue",1);
                    } 
              }  
    if(!arg || arg !="white stone") return notify_fail("你要鑲嵌(inlay)什麼？\n"); 
              { 
               if(!objectp(obj=present("white stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIW"白寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIW"白寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIW"光系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/white",1);
                    } 
              }     
    if(!arg || arg !="green stone") return notify_fail("你要鑲嵌(inlay)什麼？\n"); 
              { 
               if(!objectp(obj=present("green stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIG"綠寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIG"綠寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIW"毒系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/green",1);
                    } 
              }      
              return 1;
}                                                    
                                                                                             

#include <ansi2.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIG"綠玉髓"HIW"耳墜"NOR ,({ "chrysoprase earring","earring" }) );
  set("long",@LONG
鑲嵌綠玉髓的銀製耳墬，非常漂亮，可使用來了解物品的一些特性(showing)。
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
//    set("female_only",1);
    set("material", "stone");
    set("volume",1);
    set("unit", "對");
    set("value",4000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",2);
  setup();
}

void init()
{
  add_action("do_showing","showing");
}

int do_showing(string arg)
{
  object obj,me;
  string limit="",other="";
  int i;  
  me = this_player();
  if(!arg) return notify_fail("你要觀看什麼物品的能力值？\n");
  if( me->query_temp("armor/head")!=this_object() ) return notify_fail("你必須先戴上耳墜。\n");
  if(!objectp(obj = present(arg, me)) )
  {
    if(objectp(obj = present(arg, environment(me))) && !obj->is_character())
      tell_room(environment(me), me->name() + "盯著地上的"+obj->name() +          "，咽了一口唾沫。\n",({ me }));
    return notify_fail("你身上沒有這樣東西。\n");
  }

  tell_object(me,HIW"【"NOR+ obj->name() +HIW"】\n\n"NOR);

  if((string)obj->query("weapon_prop/damage"))
    tell_object(me,HIR"攻 擊 力"NOR""WHT"：" + obj->query("weapon_prop/damage")+"\n");
  else if((string)obj->query("armor_prop/damage"))
    tell_object(me,HIR"攻 擊 力"NOR""WHT"：" + obj->query("armor_prop/damage")+"\n");
  else
    tell_object(me,HBK"攻 擊 力"NOR""WHT"：0\n");

  if((string)obj->query("armor_prop/armor"))
    tell_object(me,HIC"防 禦 力"NOR""WHT"：" + obj->query("armor_prop/armor")+"\n");
  else
    tell_object(me,HBK"防 禦 力"NOR""WHT"：0\n");
 
  if((string)obj->query("armor_prop/shield"))
    tell_object(me,HIG"心靈抵抗力"NOR""WHT"："+obj->query("armor_prop/shield")+"\n"NOR);
  else
    tell_object(me,HBK"心靈抵抗力"NOR""WHT"：0\n"NOR);

  if((string)obj->query("value"))
    tell_object(me,HIY"物品價值"NOR""WHT"：" + obj->query("value") + "\n"NOR);
  else
    tell_object(me,HBK"物品價值"NOR"：一文不值\n");

  tell_object(me,HIW"\n  裝備條件"NOR"：\n");
  i=8; 
  switch(i)
  {
    case 8: if(obj->query("limit_lv"))limit+="            所需等級:"+obj->query("limit_lv")+"\n";
    case 7: if(obj->query("limit_skill"))limit+="            所需技巧:"+obj->query("limit_skill")+"\n";
    case 6: if(obj->query("limit_str"))limit+="            所需力量:"+obj->query("limit_str")+"\n";
    case 5: if(obj->query("limit_dex"))limit+="            所需敏捷:"+obj->query("limit_dex")+"\n";
    case 4: if(obj->query("limit_int"))limit+="            所需智慧:"+obj->query("limit_int")+"\n";    
    case 3: if(obj->query("limit_con"))limit+="            所需體質:"+obj->query("limit_con")+"\n";  
    case 2: if(obj->query("limit_exp"))limit+="            所需經驗值:"+obj->query("limit_exp")+"\n";
    case 1: if(sizeof(limit)<1)limit+="            無\n";        
  }
  tell_object(me,limit);
  tell_object(me,HIW"\n  增加屬性"NOR"：\n");
  i=23; 
  switch(i)
  {
    case 23: 
         if(obj->query("weapon_prop/str"))other+="            力量(STR)："+obj->query("weapon_prop/str")+"\n";
    case 22: 
         if(obj->query("weapon_prop/con"))other+="            體質(CON)："+obj->query("weapon_prop/con")+"\n";
    case 21: 
         if(obj->query("weapon_prop/int"))other+="            智慧(INT)："+obj->query("weapon_prop/int")+"\n";
    case 20: 
         if(obj->query("weapon_prop/dex"))other+="            敏捷(DEX)："+obj->query("weapon_prop/dex")+"\n";
    case 19: 
         if(obj->query("weapon_prop/hit"))other+="            攻擊命中率："+obj->query("weapon_prop/hit")+"\n";
    case 18: if(obj->query("weapon_prop/dodge"))other+="            閃躲迴避率："+obj->query("weapon_prop/dodge")+"\n";
    case 17: if(obj->query("weapon_prop/bio"))other+="            生物(BIO)："+obj->query("weapon_prop/bio")+"\n";
    case 16: if(obj->query("weapon_prop/bar"))other+="            獸性(BAR)："+obj->query("weapon_prop/bar")+"\n";
    case 15: if(obj->query("weapon_prop/wit"))other+="            魔法(WIT)："+obj->query("weapon_prop/wit")+"\n";
    case 14: if(obj->query("weapon_prop/sou"))other+="            心靈(SOU)："+obj->query("weapon_prop/sou")+"\n";
    case 13: if(obj->query("weapon_prop/tec"))other+="            科技(TEC)："+obj->query("weapon_prop/tec")+"\n";      
    case 12: 
         if(obj->query("armor_prop/str"))other+="            力量(STR)："+obj->query("armor_prop/str")+"\n";
    case 11: 
         if(obj->query("armor_prop/con"))other+="            體質(CON)："+obj->query("armor_prop/con")+"\n";
    case 10: 
         if(obj->query("armor_prop/int"))other+="            智慧(INT)："+obj->query("armor_prop/int")+"\n";
    case 9: 
         if(obj->query("armor_prop/dex"))other+="            敏捷(DEX)："+obj->query("armor_prop/dex")+"\n";
    case 8: 
         if(obj->query("armor_prop/hit"))other+="            攻擊命中率："+obj->query("armor_prop/hit")+"\n";
    case 7: if(obj->query("armor_prop/dodge"))other+="            閃躲迴避率："+obj->query("armor_prop/dodge")+"\n";
    case 6: if(obj->query("armor_prop/bio"))other+="            生物(BIO)："+obj->query("armor_prop/bio")+"\n";
    case 5: if(obj->query("armor_prop/bar"))other+="            獸性(BAR)："+obj->query("armor_prop/bar")+"\n";
    case 4: if(obj->query("armor_prop/wit"))other+="            魔法(WIT)："+obj->query("armor_prop/wit")+"\n";
    case 3: if(obj->query("armor_prop/sou"))other+="            心靈(SOU)："+obj->query("armor_prop/sou")+"\n";
    case 2: if(obj->query("armor_prop/tec"))other+="            科技(TEC)："+obj->query("armor_prop/tec")+"\n";      
    case 1: 
         if(sizeof(other)<1) other+="            無額外屬性\n";         
  }
  tell_object(me,other);
        
  if(obj->query_autoload()) tell_object(me,HIR"\n可儲存裝備\n"NOR);

  return 1;
}

#include <ansi.h>
#include <armor.h>
inherit WRISTS; 
void create()
{
  set_name(HIB"惡魔"NOR"之"RED"手"NOR,({"devil's arm","arm"}));
  set("long", @LONG
LONG);
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",0);
    set("material","fur");
  }
  set("limit_lv",35);
  set("limit_mks",3500);
  set("limit_con",45);
  set("limit_dex",37);
  
  set("armor_prop/damage",0);
  set("armor_prop/armor",10);
  set("armor_prop/shield",25); 
  set("armor_prop/dex",2); 
  set("armor_prop/con",2);
  setup();
}

void init()
{
     add_action("do_insert","insert");
}

int do_insert(string arg)
{
    object me = this_player(), ob = this_object(), target;
    string name;
    if( query("equipped") ) return notify_fail("請先解除該裝備。\n");
    if( !arg ) return notify_fail("你究竟要把甚麼放入惡魔之手內？\n");  
    target = present(arg, me);
    if( !target ) return notify_fail("你身上並沒有 " + arg + "。\n");
    name = target->query("id");
    
    message_vision("$N硬是把$n塞入惡魔之手內，只見一道光芒閃過，$n被惡魔之手給硬生生的吸了進去。\n", me, target);
    switch( name ){
            case "tian-demon energy":
                 message_vision("一股"HIG"淡青色"NOR"的霧氣，環繞在$N周圍，久久不能散去。\n",ob); 
                 ob->add_temp("devil_energy",1);
            break;
            default:
            break;
            }
    destruct(target);
    if( ob->query_temp("devil_energy") > 199 ) {
        ob->set("name",HIG"惡魔"NOR"之"RED"手"NOR);
        set("armor_prop/damage",0);
        set("armor_prop/armor",15);
        set("armor_prop/shield",35); 
        set("armor_prop/dex",1); 
        set("armor_prop/con",3); 
        set("armor_prop/bio",1);
        set("armor_prop/sou",-1);
    }
    return 1;
}



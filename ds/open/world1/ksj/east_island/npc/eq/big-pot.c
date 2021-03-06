#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_WATER;

void create()
{
  set_name("大鍋", ({"big pot","pot"}));
  set("long",@LONG
可以容納一個人的大鍋，鍋中正煮著不知名的液體，聞起來很噁心。
應該沒有人會傻到想去喝吧(drink)。
LONG
  );
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "個");
    set("volume",1000);
    set("value",500);
    set("water_remaining",50);
    set("drink_msg","$N伸手從$n中勺了一些液體喝了下去。\n");
  }
  setup(); 
}

void init()
{
  add_action("do_drink", "drink");
  add_action("do_putting", "putting");
}

int do_drink(string arg)
{
  object me;
  me=this_player();
  if( !this_object() ) return 0;
  if( !this_object()->id(arg) ) return 0;

  if( this_object()->query_temp("drop_crystal") )
  {
    set("heal_ap",300+random(100));
    set("heal_mp",300+random(100));
    set("heal_hp",300+random(100));
    return ::do_drink(arg);
  }
  else 
  {
    return notify_fail("你停下來想到，大鍋中的液體腥臭難聞，喝下去必定腸穿肚爛。\n");
  }
}

int do_putting(string str)
{
  object me,b,z,ob;
  me=this_player();
 
  if(!str || str!="crystal") return 0;
  if(!objectp(z=present("ice crystal",me) ) )
    return notify_fail("你沒有東西可以放。\n");
   
  destruct(z);
  message_vision(HIW"\n$N將一個物事丟入大鍋中，隨後鍋中冒出絲絲白煙！\n"NOR,me);
  this_object()->set_temp("drop_crystal",1);
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  this_object()->delete_temp("drop_crystal");
}

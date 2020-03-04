#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIY"陽 石"NOR, ({ "sun stone", "stone" }));
  set("long",@LONG
一顆未經琢磨原石，似乎能跟陰石合而為一的樣子•
LONG
);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1); 
    set("combine_stone", 1);
  }
  setup();
}

void init()
{
  add_action("do_combine","combine");
}
int do_combine(string str)
{
  int i,j;
  object *inv,ob1,ob2,ob3,me;
  me = environment(this_object());
  if( this_player() != me ) return 0;
  j=0;
  if(!str || str!="stone") return 0;
  inv = all_inventory(environment( this_object() ));
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i]->query("id")=="sun stone") j +=1000; ob1=inv[i];
    if(inv[i]->query("id")=="moon stone") j +=20;  ob2=inv[i]; 
  }
  if(j == 1020)
  { 
    new(__DIR__"sun-moon_stone" )->move(environment(this_object()));
    message_vision(HIR"$N將陽石和陰石放在一起，用盡身上內力硬是將它們結合！\n"NOR,me);
    tell_object(me,HIG"你得到一顆陰陽石！\n"NOR);
    me->set("ap",0);
    destruct(present("sun stone",this_player())); 
    destruct(present("moon stone",this_player()));
  }
  else return notify_fail("你身上只有一顆石頭而已！\n");
  return 1;
}

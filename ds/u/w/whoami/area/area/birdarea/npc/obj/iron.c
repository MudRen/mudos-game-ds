#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"精鐵石"NOR,({ "top_grade iron stone","stone" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","稀有的鐵石。\n");
                set("unit","個");
                set("value",100);
        }
        setup(); 
  set("combine_stone_1",1);
}
void init()
{
  add_action("do_combine","combine");
}

int do_combine(string str)
{
  int i,j;
  object *inv,ob1,ob2,me;
  me = environment(this_object());
  if( this_player() != me ) return 0;
  j=0;
  if(!str || str!="stone") return 0;
  inv = all_inventory(environment( this_object() ));
  for(i=0;i<sizeof(inv);i++)
  {
    if( inv[i]->query("combine_stone_1") ) j++;
    if(inv[i]->query("combine_stone_1") && j==1) ob1=inv[i];
    if(inv[i]->query("combine_stone_1") && j==2) ob2=inv[i];
  }
  if(j >= 2)
  {
    new(__DIR__"sun-moon_iron_stone" )->move(environment(this_object()));
    message_vision(HIB"$N將陰陽石和精鐵石放在一起，用盡身上內力硬是將它們結合！\n"NOR,me);
    tell_object(me,HIG"你得到一顆陰陽鐵石！\n"NOR);
    me->set("ap",0);
    destruct(ob2);
    destruct(ob1);
  }
  else return notify_fail("你身上只有一顆石頭而已！\n");
  return 1;
}


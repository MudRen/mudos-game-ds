#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW+BLK"�� ��"NOR, ({ "moon stone", "stone" }));
  set("long",@LONG
�@�����g�Z�i��ۡA���G��򶧥ۦX�Ӭ��@���ˤl�E
LONG
);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
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
    message_vision(HIR"$N�N���۩M���۩�b�@�_�A�κɨ��W���O�w�O�N���̵��X�I\n"NOR,me);
    tell_object(me,HIG"�A�o��@�������ۡI\n"NOR);
    me->set("ap",0);
    destruct(present("sun stone",this_player())); 
    destruct(present("moon stone",this_player()));
  }
  else return notify_fail("�A���W�u���@�����Y�Ӥw�I\n");
  return 1;
}

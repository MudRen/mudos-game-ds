//2003.3.14 �s�Wcombine�� fly-sea-stone ���\��  by ksj
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIC"�� �� ��"NOR, ({ "sea stone", "stone" }));
  set("long",@LONG
�@�������ẫ���ɥۡA�q�Ϊ��i�H�ݥX�g�L����J�Z�A�Pı���ѤO�q
�R����P��A�Ѯ��ۤ����|�ۤ��l�޵��X(combine)�C
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1);
    set("no_sell", 1);
    set("no_sac", 1);
    set("seastone", 1);
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
    if( inv[i]->query("seastone") ) j++;
    if(inv[i]->query("seastone") && j==1) ob1=inv[i];
    if(inv[i]->query("seastone") && j==2) ob2=inv[i];
    if(inv[i]->query("seastone") && j==3) ob3=inv[i];
  }
  if(j >= 3)
  {
    new(__DIR__"fly-sea-stone" )->move(environment(this_object()));
    message_vision(HIW"$N�N�T���Ѯ��۩�b�@�_�A�Ѯ��ۥߧY�l�޵��X�A�o�Xģ�����~�C\n"NOR,me);
    destruct(ob3);
    destruct(ob2);
    destruct(ob1);
  }
  else if(j >= 2)
  {
    message_vision("$N�N�Ѯ��۩�b�@�_�A�Ѯ��۬ۤ��l�ޡA�u�O����C\n",me);
  }
  else return notify_fail("�A���W�u���@���Ѯ��ۦӤw�I\n");
  return 1;
}

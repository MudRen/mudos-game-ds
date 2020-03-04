#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("�a�ä����Ĺ�", ({"bodhisattva statue","statue"}));
  set("long",@LONG
�@�L�����ֲ֪��۹��A�h�~�e���H�]�m�Ψ���������A�ѩ�ʥF��µ
�ܱo��@����䪺���Y�S��ˡA���ߤH�h�i�H�����M�z�@�U(clean)�C
LONG);
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "��");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_clean", "clean");
}

int do_clean(string str)
{
  object me,b;
  me=this_player();
 
  if(!str || str!="statue") return 0;
  if(query_temp("be_clean") )
     return notify_fail("�۹��w�g�Q���ˤF�A�S���n�A�M�z�F�C\n");
  message_vision(HIW"\n$N�J�Ӧa���h�򹳤W���d�СA�åB�ޱ��|�P������A\n"
                    "�@���p�߱��ˤF�۹��A�q���y�_�X�@�}�C�ϡI\n"NOR,me);
  set_temp("be_clean",1);
  b=new(__DIR__"npc/ghost" );
  b->move(environment(this_object()));
  b=new(__DIR__"npc/eq/protect-amulet" );
  b->move(environment(this_object()));
  set("long",@LONG
�@�L�����ֲ֪��۹��A�����D�Q�ֵ����ˤF�A�۹������U��F�@�ǩG��C
LONG);
  call_out("delay",1200,this_object());
  return 1;
}

void delay(object room)
{
  set("long",@LONG
�@�L�����ֲ֪��۹��A�h�~�e���H�]�m�Ψ���������A�ѩ�ʥF��µ
�ܱo��@����䪺���Y�S��ˡA���ߤH�h�i�H�����M�z�@�U(clean)�C
LONG);
  this_object()->delete_temp("be_clean");
}

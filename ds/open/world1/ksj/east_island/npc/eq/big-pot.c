#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_WATER;

void create()
{
  set_name("�j��", ({"big pot","pot"}));
  set("long",@LONG
�i�H�e�Ǥ@�ӤH���j��A�礤���N�ۤ����W���G��A�D�_�ӫ����ߡC
���ӨS���H�|�̨�Q�h�ܧa(drink)�C
LONG
  );
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
    set("water_remaining",50);
    set("drink_msg","$N����q$n���c�F�@�ǲG��ܤF�U�h�C\n");
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
    return notify_fail("�A���U�ӷQ��A�j�礤���G��{�����D�A�ܤU�h���w�z��{��C\n");
  }
}

int do_putting(string str)
{
  object me,b,z,ob;
  me=this_player();
 
  if(!str || str!="crystal") return 0;
  if(!objectp(z=present("ice crystal",me) ) )
    return notify_fail("�A�S���F��i�H��C\n");
   
  destruct(z);
  message_vision(HIW"\n$N�N�@�Ӫ��ƥ�J�j�礤�A�H���礤�_�X�����շϡI\n"NOR,me);
  this_object()->set_temp("drop_crystal",1);
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  this_object()->delete_temp("drop_crystal");
}

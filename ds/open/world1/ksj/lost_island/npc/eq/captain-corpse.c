#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("���������", ({"captain's corpse","corpse"}));
  set("long",@LONG
�@��W�����ۨǳ\��ת��հ��A�q�窫�H���i�H�q�X�j���O�@����
�A�u�����a�R��󦹡A��@�U�]�\�d������򪫡C
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",1);
    set("value",0);
    set("no_get",1);
  }
  setup(); 
}

void init()
{
  add_action("do_search","search");
}

int do_search(string str)
{
  object me,ob;
  me=this_player();
  ob=new(__DIR__"captain-hat");

  if( me->is_busy() )
    return notify_fail("�A�٦b���A�S�ɶ��ˬd�C\n");
  if( me->is_fighting() )
    return notify_fail("�A���b�԰����A�L�v���ߡC\n");
  if(!str || str!="corpse")
    return 0;
  else
  {
    message_vision("\n$N�J�ӧ�F�䰩�e�Υ|�P�A�b���������e�����@�����Z���㪺�U�l�C\n"NOR,me);
    ob->move(me);
    me->start_busy(2);
    destruct(this_object());
  }
  return 1;
}

#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("����", ({"big stone","stone"}) );
  set("long",@LONG
�@�ӥ��j�����Y�A���y�p�s�����צ�F�s�D�A�ݨӬO���h�~���y����
�A�O�q�j���H�γ\�i�H����(move)���C
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "��");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_move","move");
}

int do_move(string str)
{
  object me;
  me=this_player();
  if(!str || str!="stone") return 0;
  if( me->query("str") < 110 ) return notify_fail("�A�ϫl�Q���ʥ��ۡA�L�`�O�𤣰��C\n");
  message_vision(HIW"\n$N��������A�ϺɦY�����O��C�C�a�N���۲��ʨ�@�ǡC\n"NOR,me);
  destruct(this_object());
  return 1;
}

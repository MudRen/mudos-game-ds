inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"�L"HIR"��"BLK"�U"HIR"��"HIC"��"NOR, ({ "super kaleidoscope", "kaleidoscope" }));
  set("long",@LONG
�q�LISO 9002��ګ~��O�Ҫ���ɪŤj�_���A�ϥΪ��ɭԥu�n���Ufire
�A�N�i�H��F�@��۪Ŷ��I�I
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

void init()
{
  add_action("do_fire","fire");
}

int do_fire()
{
  object z,me;
  me=this_player();
  if(!objectp(z=present("super kaleidoscope",this_player()) ) )
    return notify_fail(HIR"Kenshin�i�D�A:"NOR"�Х��T�ϥΥ����~!!�C\n"NOR);
 message_vision(HIG"$N���U�F"HIR"F I R E "HIG"�s�A��M���Ѧ�@�t�A�H��Ӯ����b�Ů�!!\n"NOR,me);
  this_player()->move("/u/k/kenshin/dream-fight/r5");
  if( userp(this_player()) )
    {
      message("world:world1:vision",
        HIC"\n�i"HIB"�Z�L"HIR"����"HIC"�j"HIR""+this_player()->name(1)+HIG"��V�ɪšA�Ө�F�w"HIM"�ڤ��v�޳�"HIB"�E�E�E\n\n"NOR
        ,users());
    }

  tell_room(environment(me),me->query("name")+HIR" �Ө�F�o�ӪŶ�...\n"NOR,me );
  destruct(this_object());
  return 1;
}


inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIC"�ѵ��]"NOR, ({ "sky bead", "bead" }));
  set("long",@LONG
�Ѿ��ѩҳy�A�i�������V�F���X���q(fly)�C
LONG);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1000);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

void init()
{
  add_action("do_fly","fly");
}

int do_fly()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("sky bead",this_player()) ) )
    return notify_fail("�A�S���F��i�H�ϥΡC\n");
  if( strsrch(file_name(env), "east_island") != -1 )
    return notify_fail("�A�w�g�b�F���X���q�F�C\n");
  if( me->is_fighting() )
    return notify_fail("�A���b�԰����A�L�v���ߡC\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
    return notify_fail("���B�L�k�ϥΤѵ��]�C\n");
  if( env->query("no_recall") )
    return notify_fail("���B�L�k�ϥΤѵ��]�C\n");
  message_vision(HIW"$N����X���ѵ��]�A�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
  this_player()->move("/open/world1/ksj/east_island/room1");
  tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
  destruct(this_object());
  return 1;
}

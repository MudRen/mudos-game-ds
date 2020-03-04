// 2003.3.14  �s�W,�ѤT�� sea-stone �X�ֲ���   by ksj
inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"�� �� ��"NOR, ({ "fly sea stone", "stone" }));
  set("long",@LONG
�ѤT���Ѯ��۵��X�Ӧ��A�Ѯ��ۤ��۲o����¶�K���i���A��b���_�C
���㦳�������O�q(fly)�C
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1);
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
  if(!objectp(z=present("fly sea stone",this_player()) ) )
    return notify_fail("�A�S���F��i�H�ϥΡC\n");
  if( strsrch(file_name(env), "lost_island") != -1 )
    return notify_fail("�A�w�g�b��@�q�C\n");
  if( me->is_fighting() )
    return notify_fail("�A���b�԰����A�L�v���ߡC\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
    return notify_fail("���B�L�k�ϥε����ۡC\n");
  if( env->query("no_recall") )
    return notify_fail("���B�L�k�ϥε����ۡC\n");
  switch(random(5))
  {
    case  0: 
          message_vision(HIW"$N���|�����ۡA�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room13");
          tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
          break;
    case  1: 
          message_vision(HIW"$N���|�����ۡA�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room10");
          tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
          break;
    case  2:
          message_vision(HIW"$N���|�����ۡA�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room28");
          tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
          break;
    case  3:
          message_vision(HIW"$N���|�����ۡA�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room4");
          tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
          break;
    case  4:
          message_vision(HIW"$N���|�����ۡA�H�ᨭ�ΤƬ��@�D�ե��R�V�ѻڡC\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room17");
          tell_room(environment(me),me->query("name")+"�q�b�Ť��L�F�U�ӡC\n",me );
          break;
  }
  if(query_temp("used"))
  {
    message_vision(HIR"�����۵o�X�����Ƭ����u�F�C\n"NOR,me);
    destruct(this_object());
  }
  set_temp("used",1);
  set_name(HIW"�� �� ��"NOR"(�b�l�a)", ({ "fly sea stone", "stone" }));
  return 1;
}

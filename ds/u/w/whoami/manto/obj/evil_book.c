inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(RED"�m�]���g�n"NOR, ({ "evil book", "book" }));
  set("long",@LONG
�@���¦�ʥ֪��ѡA�m�]���g�n�T�Ӧr�b�ʭ��W�{�{�۶¨~�A�o����
�N���@���Ӧۦa���`�W�̪��]���A�t�t�l�`�ۧA���F��C

���G�����n���@���ʫP�A½�}�\Ū��(Read)�C
LONG);
set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "��");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_read","read");
}

int do_read()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("evil book",this_player()) ) )
    return notify_fail("�A�S���F��i�H�ϥΡC\n");
  if( me->is_fighting() )
    return notify_fail("�A���b�԰����A�L�v���ߡC\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
   return notify_fail("���B�L�k�ϥ�"NOR+RED"�]���g�C\n"NOR);
  if( env->query("no_recall") )
    return notify_fail("���B�L�k�ϥ�"NOR+RED"�]���g�C\n"NOR);
  message_vision(HIW"$N��Ÿ�ݪ�����½�}"NOR+RED"�]���g"NOR+HIW"�A�g�Ѭ�M���o�F���ꪺ�����A�b�o�@�����������A"NOR+HIR"�]���g"NOR+HIW"�T�Ӧr�{�ʵ۲`�㪺�¨~�C\n"NOR,me);
message("world:world1:vision",
CYN"\n"+me->query("name")+"�����g���A��f���n��D�G�u"NOR+RED"�ͤ��͡A���H����A�ëD�áA�]���䤤�A���H�����d��ơA���Ƭ��]�W����"NOR+CYN"�v\n\n"NOR
        ,users() );
       call_out("wakeevil",7);
  return 1;
}

void wakeevil()
{
        message("world:world1:vision",
CYN"\n�A����ǨӼҽk���q�n�C�C�C\n"NOR
WHT"\t\n�֤��A�פ��A�Һ��H���A�F���A�����A��H���]�H�C�C�C�C�C�C\n"NOR
        ,users() );
  destruct(this_object());
        return;
}

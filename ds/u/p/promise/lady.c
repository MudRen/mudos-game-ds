#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIM"����"HIW"�p"HIR"��"HIW"�U"NOR,({"doll lady","christmas","lady"}));
set("gender","�k��");
set("race","�H��");
set("title",HIR"�������֤k"NOR);
  set("long",
"�n�����ի����Х�(want)!!\n",
);
       set("age", 14);
       set("combat_exp", 0);
       set("attitude", "friendly");

setup();
}
void init()
{
add_action("do_want", "want");
}
int do_want(string arg)
{

       object me,dolls,doll;
       me = this_player();
       dolls=new(__DIR__"test_doll");
       if(objectp(doll = present("test doll", me) ))
       return notify_fail(HIY"�u�O�g�ߪ��H�A�ڰQ���A>.<~\n"NOR);
      else  
{
message_vision(HIM"�t��"HIW"�p���U"NOR"��"+me->query("name")+"�@��"HIG"���ի���"HIR""NOR"�A�åB��"+me->query("name")+"������[�[�o�I�I\n"NOR,me);
dolls->move(me);
 }
       return 1;
}


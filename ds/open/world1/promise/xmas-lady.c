#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIM"�t��"HIW"�p"HIR"��"HIW"�U"NOR,({"christmas lady","christmas","lady"}));
set("gender","�k��");
set("race","�H��");
set("title",HIR"���~���֤k"NOR);
  set("long",
"�n���~�Х�(want)!!\n",
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
       object me,gift;
       me = this_player();
       
if (me->query("age") <= 17 )
     return notify_fail(HIW"�A�S��殳����~�C\n"NOR);


       if(me->query("xmas-gift"))
       return notify_fail(HIY"�u�O�g�ߪ��H�A�ڰQ���A>.<~\n"NOR);
       else
{
me->set("xmas-gift",1);
gift=new(__DIR__"xmas-gift");
message_vision(HIM"�t��"HIW"�p���U"NOR"��"+me->query("name")+"�@��"HIR"�t��§��"NOR"�A�åB��"+me->query("name")+"������[�[�o�I�I\n"NOR,me);
gift->move(me);
}

       return 1;
}





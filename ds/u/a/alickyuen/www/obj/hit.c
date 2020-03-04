#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"�V�T�p"NOR,({ "hit" }));
    if( clonep() )
    set_default_object(__FILE__);
    else
    {
       set("can_give",1);
    }
    setup();
}

void init()
{
    add_action("do_hit", "hit");
}

int do_hit(string arg)
{
    object obj,me;
    me = this_player();

    if(!arg) return notify_fail("<�榡>:hit <Player ID>\n"); 
    if(!obj = present(arg, environment(me)))
       return notify_fail("�o�̨S���o�ӤH�C\n");
    message_vision(HIY"\n\n\n\n\n$n�ΤO��$N���Y�V�U�h�C\n\n\n\n\n"NOR,obj,me);
    obj->start_busy(26);
    obj->set_temp("hit",1); 
    call_out("hit",1,obj);
    return 1;
}

int hit(object obj)
{
      int i;
      object me;
      me = this_player();
      i = obj->query_temp("hit");

//      if(!interactive(obj))
//         return notify_fail(HIR"����Ƥ]�S�o��...\n");
      switch( i ) {
          case 1:
            tell_object(obj,HIR"�A���Y���P�P�A���������h�N��....\n\n\n\n\n\n\n"NOR);
            obj->disable_player_cmds("�A�٦b���g�C\n");
            obj->set_temp("define_look",NOR" �����b�o�� "HIR"[���g��]"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 2:
            tell_object(obj,HIW"�ҽk���N�Ѥ��A�ڨ�ۤv���b�r�b...\n\n\n\n\n\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 3:
            message_vision(HIR"$N���K�b�r�b���r�����A�n���ּ�...\n\n"NOR,obj);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 4:
//            tell_object(users(),HIR+obj->query("name")+HIR+"�ϫl�j�ۡR�ڷR�r�b���\n"NOR);
            tell_object(obj,HIW"�@�Ӥ��p�ߤӹL���ġA���R��A�S���F�L�h...XD\n\n\n\n\n\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 5:
            tell_object(obj,HIR"�@�q�ɶ���A������_�N��...\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 6:
            message_vision(YEL"$N"YEL"���۪F����, �誦��, �����S���������j�s: �ڧ����n�����\n"NOR,obj);
            obj->delete_temp("hit"); 
            obj->delete_temp("define_look");
            obj->enable_player_cmds();
            break;
          }
}

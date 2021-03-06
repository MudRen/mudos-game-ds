//
//      surrender.c
//
// 改成需要雙方都下才能
// 要求 surrender 的人直接打 surrender
// 但是被要求的人要打 surrender <要求的人>
// 要求的人 -> set_temp("surrender/" + target->query("id"), 1);
// 被要求的人-> set_temp("surrender/" + me->query("id"), 2);

#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, *enemy;
        mapping surrender;
        string *flg;

        if( !me->is_fighting() )
                return notify_fail("你不在戰鬥中。\n");

        if( arg )
        {
                if( !me->query_temp("apt_surrender") )
                        return notify_fail("並沒有人向你求饒喔。\n");
		if( me->query_temp("apt_surrender/"+arg) )
                {
                        if( ob = find_player(arg) && ob->query_temp("surrender/"+me->query("id")) )
                        {
//                              if( me->remove_enemy(ob) && ob->remove_enemy(me) )
                                message_vision("$N接受了$n的投降。\n", me, ob);
                                return 1;
                        }
                }
                else return notify_fail("這個人有向你求饒嗎？\n");
        }
        else {
                if( arrayp(enemy=me->query_enemy()) && sizeof(enemy) )
                {
                        message_vision( HIW "\n$N說道﹕「不打了﹐不打了﹐我投降....。」\n\n" NOR, me);
                        foreach(object target in enemy)
                        {
                                if( target->query_temp("surrender/"+ me->query("id")) )
                                {
                                        me->remove_enemy(ob);
                                        ob->remove_enemy(me);
                                        message_vision("$N接受了$n的投降。\n", me, ob);
                                        return 1;
                                }       
                                tell_object(target, HIY+me->name()+"("+me->query("id")+") 狼狽的向你求饒 (surrender "+ me->query("id")+ ")\n"NOR );
                                target->set_temp("apt_surrender/"+me->query("id"), 1);
                                me->set_temp("surrender/"+target->query("id"), 1);
                        }
                }
        }
        return 1;
}
//                      ob = offensive_target(me);

int help(object me)
{
  write(@HELP
指令格式 : surrender
 
這個指令可以讓你終止戰鬥。
注意, 需要對方也下surrender指令才可以.
 
HELP
    );
    return 1;
}


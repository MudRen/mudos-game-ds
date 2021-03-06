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

        if( !me->is_fighting() )
                return notify_fail("你不在戰鬥中。\n");

        if( arg )
        {
                if( !me->query_temp("apt_surrender") )
                        return notify_fail("並沒有人向你求饒喔。\n");
                if( me->query_temp("apt_surrender/"+arg) )
                {
                        if( objectp(ob = find_player(arg)) && ob->query_temp("surrender/"+me->query("id")) )
                        {
                                me->remove_killer(ob);
                                ob->remove_killer(me);
                                me->delete_temp("killer");
                                ob->delete_temp("killer");
                                me->delete_temp("apt_surrender/"+arg);
                                ob->delete_temp("surrender/"+me->query("id"));
                                if( ob->query("popularity") >= 5)
                                        ob->add("popularity", -5);
                                message_vision("$N接受了$n的投降。\n", me, ob);
                message("world:world1:vision",
                   HIM"【謠言】江湖上不知哪來的消息，說道"+ HIW"" + ob->name()+HIM"竟然跟"+ HIW "" + me->name() + HIM"下跪求饒。\n"+NOR
                ,users());
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
                                if( !userp(target)) continue;
                                tell_object(target, HIY+me->name()+"("+me->query("id")+") 狼狽的向你求饒，如果你要原諒他，請你打 surrender "+ me->query("id")+ "\n"NOR );
                                target->set_temp("apt_surrender/"+me->query("id"), 1);
                                me->set_temp("surrender/"+target->query("id"), 1);
                        }
                }
        }
        return 1;
}


int help(object me)
{
  write(@HELP
指令格式 : surrender
 
這個指令可以讓你終止戰鬥。
注意，需要對方也對你下surrender指令才可以。

由於投降是一件不名譽的事，所以你的個人聲望會有所損失。
 
HELP
    );
    return 1;
}


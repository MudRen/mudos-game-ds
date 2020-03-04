//
//      surrender.c
//
// �令�ݭn���賣�U�~��
// �n�D surrender ���H������ surrender
// ���O�Q�n�D���H�n�� surrender <�n�D���H>
// �n�D���H -> set_temp("surrender/" + target->query("id"), 1);
// �Q�n�D���H-> set_temp("surrender/" + me->query("id"), 2);

#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, *enemy;

        if( !me->is_fighting() )
                return notify_fail("�A���b�԰����C\n");

        if( arg )
        {
                if( !me->query_temp("apt_surrender") )
                        return notify_fail("�èS���H�V�A�D�ǳ�C\n");
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
                                message_vision("$N�����F$n���뭰�C\n", me, ob);
                message("world:world1:vision",
                   HIM"�i�����j����W�������Ӫ������A���D"+ HIW"" + ob->name()+HIM"���M��"+ HIW "" + me->name() + HIM"�U���D�ǡC\n"+NOR
                ,users());
                                return 1;
                        }
                }
                else return notify_fail("�o�ӤH���V�A�D�ǶܡH\n");
        }
        else {
                if( arrayp(enemy=me->query_enemy()) && sizeof(enemy) )
                {
                        message_vision( HIW "\n$N���D�R�u�����F�M�����F�M�ڧ뭰....�C�v\n\n" NOR, me);
                        foreach(object target in enemy)
                        {
                                if( !userp(target)) continue;
                                tell_object(target, HIY+me->name()+"("+me->query("id")+") �T�V���V�A�D�ǡA�p�G�A�n��̥L�A�ЧA�� surrender "+ me->query("id")+ "\n"NOR );
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
���O�榡 : surrender
 
�o�ӫ��O�i�H���A�פ�԰��C
�`�N�A�ݭn���]��A�Usurrender���O�~�i�H�C

�ѩ�뭰�O�@�󤣦W�A���ơA�ҥH�A���ӤH�n��|���ҷl���C
 
HELP
    );
    return 1;
}


#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob;

        seteuid(getuid(me));
        if(!str) return notify_fail("���O�榡: shutup <�ϥΪ�>\n");
        ob = LOGIN_D->find_body(str);
        if(!ob) return notify_fail("�u�W���ϥΪ̤��S���o�ӤH�C\n");
        if(wiz_level(me) <= wiz_level(ob))
        return notify_fail("�H�U�ǤW�A�Q���]���O�o�ˡC\n");

        seteuid(geteuid(ob));
        if (ob->query("shutup") == "on")
        {
                ob->delete("shutup") ; 
                tell_object(ob, "�Ův("+me->query("id")+")�����A���T��\n");
                tell_object(me,"�A�����F���a("+ob->query("id")+")���T��\n");
                tell_object(users(),HIW"\n�@�@�@((((("HIR"�ѯ�"HIY"�I�S"HIW")))))�@�@�@"NOR""HIM+ob->name()+NOR"�H���@��u"HIC"���������"NOR"�A�Ův"HIW+me->name()+NOR"�S���}�@���A��_�v�O�I\n\n"+NOR);
        }
        else
        {
                ob->set("shutup", "on") ;
                tell_object(ob, "�Ův("+me->query("id")+")�T��A�ϥΤ��@�W�D\n");
                tell_object(me,"�A�Ұʪ��a("+ob->query("id")+")���T��\n");
                tell_object(users(),HIW"\n�@�@�@((((("HIR"�ѯ�"HIY"�I�S"HIW")))))�@�@�@"NOR""HIM+ob->name()+NOR"�]�H��"HIC"���������"NOR"�A�ҥH�Q�Ův"HIW+me->name()+NOR"�T���I\n\n"+NOR);
        }
        return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : quiet <�Y�H>

��Q�T���̦A���ϥ�quiet �N��������T��
�����O�i���A(�p)�N�Y�H�T��ϥΤ����W�D�C
HELP
    );
    return 1;
}


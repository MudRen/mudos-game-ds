//praise.c By tmr
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
inherit SSERVER; 
 
int main(object me, string arg)
{
        object ob;
        int p,lv;

        seteuid(getuid(me));
        lv=me->query("level");
 
        if( lv < 10 )
                return notify_fail("�A�����n�ɨ�Q�šA�g���~�|���ġC\n");
        if( lv <= me->query("praised") )
                return notify_fail("�A�w�g�g���L�F�C\n");
        if(!arg) 
                return notify_fail("�A�n�g���֩O�H\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) return notify_fail("�u�W�èS���o�ӤH�C\n");
        }
	shout(GRN +me->name()+"�g���F"+ ob->name()+ GRN +"�I�I\n" NOR);
        write("ok.\n");
//        ob->add("popularity",(lv-9)*3); //�n��
//        me->set("praised", lv );
        return 1;       
}
int help(object me)
{
        write(@HELP
���O�榡 :praise <��H�W��>
 
�o�ӫ��O�i�H���A�Ψ��g���O�H�A�ӧO�H�|�]���A���g���Ӵ����n��C

HELP
    );
    return 1;
}



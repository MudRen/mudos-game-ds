// talent cmds - tmr 2008/07/31

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    mapping my;
    string str="";
    seteuid(getuid(me));

    if(!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("�A�n��ݽ֪����Ū��A�S\n");
    } else
        return notify_fail("�u���Ův���ݧO�H�����Ū��A�C\n");

    my = ob->query_entire_dbase();

    str = sprintf("�ثe�i�Ϊ��ѽ��٦� %d �I�C\n", my["gifts"]  );
   

    write(str);
    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : talent
           talent <��H�W��>                   (�Ův�M��)

          �o�ӫ��O�i�H�d�ߧA���ѽ��I�ƤΤѽ᪺��ܡC

HELP
         );
    return 1;
}



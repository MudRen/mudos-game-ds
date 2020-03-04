inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object who;
        
    if( arg && !wizardp(me) )
        return notify_fail("�u���Ův�~��d�ߧO�H���s�ڡC\n");

    if( !arg ) who = me;
    if( arg=="ALL") {
        object* ob;
        string msg ;
        int i;

        ob = sort_array( users(), "sort_user" );

        msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        for(i=0;i<sizeof(ob);i++) {
        msg += sprintf("�x%12s%-12s %40s �T�ɪO�x\n",
                       ob[i]->query("name"),
                       "("+ ob[i]->query("id") + ")",
                        chinese_number(ob[i]->query("bank/past"))
                      );

        }
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        //tell_object(me, msg);
        me->start_more(msg);
        return 1;
    }
    else {
        if( !who ) who = present(arg, environment(me));
        if( !who ) who = find_living(arg);
        if( !who ) return notify_fail("�S�� " + arg + " �o�ӤH���C\n");
        write( sprintf("[%s(%s)] ",who->name(), who->query("id")));
    }

    tell_object(me, "�A�ثe��" + chinese_number(who->query("bank/past")) + "�T�ɪO���s�ڡC\n");

    return 1;
}

int sort_user(object ob1, object ob2)
{
    return ob2->query("bank/past")- ob1->query("bank/past");
}

int help()
{
    write(@TEXT
���O�榡�Rbalance [�Y�H|ALL]

�o�ӫ��O�i�H�d�ߧA�Ȧ�ثe���s�ڡC
TEXT);
    return 1;
}


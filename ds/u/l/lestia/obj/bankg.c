#include <ansi.h>

inherit EQUIP;

void create()
{
        seteuid(getuid());
        set_name(HIW"�]���լd��"NOR,({"search tool","serach","tool"}));
        set("unit","��");
        set_weight(1000);
        setup();
}

void init()
{
add_action ("do_search", "search");
}
int do_search()
{
        int i,j=0;
        object *user_list;

        user_list=users();
        i=sizeof(user_list);
        write("�ˬd�����b�d�ߪ��a�Ȧ檺���....\n");
        while(i--)
        {
       if (user_list[i]->query("bank/past")>100000)
                {
                        write(sprintf("��� [ %d %s(%s) �Ȧ�s�� : %d �� ]\n",
                        j,
                        (string)user_list[i]->query("name"),
                        (string)user_list[i]->query("id"),
                        (int)user_list[i]->query("bank/past")));
                        j++;
                }
 }
        return 1;
}



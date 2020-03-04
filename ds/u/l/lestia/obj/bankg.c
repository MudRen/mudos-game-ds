#include <ansi.h>

inherit EQUIP;

void create()
{
        seteuid(getuid());
        set_name(HIW"財產調查器"NOR,({"search tool","serach","tool"}));
        set("unit","件");
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
        write("檢查器正在查詢玩家銀行的資料....\n");
        while(i--)
        {
       if (user_list[i]->query("bank/past")>100000)
                {
                        write(sprintf("顯示 [ %d %s(%s) 銀行存款 : %d 元 ]\n",
                        j,
                        (string)user_list[i]->query("name"),
                        (string)user_list[i]->query("id"),
                        (int)user_list[i]->query("bank/past")));
                        j++;
                }
 }
        return 1;
}



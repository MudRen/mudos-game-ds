#include <ansi.h>
inherit ITEM;

int sort_user(object ob1,object ob2);

void create()
{
    set_name("�C��",({"future list","list"}) );
    set("long","�o�O�@�ӥΨӦC�X�bfuture ��user�C\n");
    set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1);
        set("no_sac",1);
        }
        setup();
}

void init()
{
      add_action("do_flist","flist");
}

int do_flist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        
        me=this_player();
        str = "��  ���Ӫ��a�C��  \n";
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if(list[j]->money_type()!=3 ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
                        str += list[j]->query("name")+"("+list[j]->query("id")+")\n";
                        ppl_cnt++;
                }
                
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}



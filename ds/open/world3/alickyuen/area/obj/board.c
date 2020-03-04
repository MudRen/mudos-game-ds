#include <ansi.h>
inherit ITEM;
int sort_user(object ob1, object ob2);
void create()
{
        set_name(HIM"電子告示板"NOR, ({ "board" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",
                        "一個電子告示板，你可以打ｌｉｓｔ來看看現時的入院名單。\n"
                        );
                set("value", 0);
                set("no_get",1);
                  set("no_sac",1);
        }
}
void init()
{
      add_action("do_list","list");
}
int do_list()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        me=this_player();
        str = HIW "◎　現時入院名單　◎ \n" NOR;
        str += "─────────────────────────────────────\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        if( !environment(list[j]) ) continue;
                        if(!list[j]->query_temp("Find_An/host") ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
          str = sprintf("%s%-30s%s",
           str,
              "第"+(string)ppl_cnt+"名："+list[j]->query("name"),
              (string)list[j]->query("Find_An/host")+"隻。\n",
           );
                        ppl_cnt++;
                }
                
        str += "─────────────────────────────────────\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = ob1->query_temp("Find_An/host")-ob2->query_temp("Find_An/host");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}

#include <ansi.h>
inherit ITEM;

int sort_user(object ob1,object ob2);

void create()
{
    set_name("�C��",({"game list","list"}) );
    set("long","�t�Ϥ����j�ɨ��C��\n");
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
   add_action("do_gamelist","gamelist");
}

int do_gamelist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        
        me=this_player();
        str = "��  �t�Ϥ������ɨ��u�W�ƦW \n";
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                          if(!list[j]->query("game_score") ) continue;
                  if(!me->visible(list[j])) continue;
//                            if(wizardp(list[j]) ) continue;
                        str += "��"+(string)ppl_cnt+"�W�G"+list[j]->query("name");
                          str +="      "+(string)list[j]->query("game_score")+"���C\n";
if(list[j]->query("game_score")) list[j]->delete("game_score");
                        ppl_cnt++;
                }
                
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

          ord = ob1->query("game_score") - ob2->query("game_score");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}



// where.c
// 2006/10/02
// update by Tmr

inherit F_CLEAN_UP;

int all(object me);
int single(object me, string str);

int main(object me, string str)
{
        if (!str)
                return all(me);

        return single(me, str);
}


// 查詢所有玩家的位置
int all(object me) 
{
        object ob, where, *ob_list;
        string msg;

        ob_list = sort_array( users(), (:
                        strcmp( environment($1) ? file_name(environment($1)) : "",
                                        environment($2) ? file_name(environment($2)) : "" )
                :) );
        msg = "\n                    名稱(ID)                               地   點                      \n";
                foreach(ob in ob_list) {
                         if( !environment(ob) || !this_player()->visible(ob) ) continue;
                        where = environment(ob);

                           msg += sprintf("%24s%-14s - %20s %-45s\n",
                                ob->name(),
                                "("+ ob->query("id") +")",
                                  (string)where->query("short"), (string)file_name(where) );
                }
        msg += "\n";

        me->start_more(msg);
        return 1;
}

// 查詢特定玩家的位置
  int single(object me, string str) 

{
        object ob, where, *ob_list;
        int i;

        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
                return 1;
        }
        if (!ob) return notify_fail("現在沒這個人.\n");
        where = environment(ob);
        if (!where) return notify_fail("這個人不知道在那裡耶...\n");
        printf("%s(%s) at %s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
    return 1;

}

int help(object me)
{
        write(@HELP
指令格式: where 
          where [玩家的 ID]

這個指令是用來得知所有玩家，或是特定玩家目前所在的位置。

HELP
        );
        return 1;
}


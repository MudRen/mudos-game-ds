// set.c
// Cominging 改過加追蹤器, 將原本使用 bug 的人記錄下來
// 把可能 set 的 setting 加入 list 中
// 非 settings 的就 record 下來
 
#define MAX_ENV_VARS    20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
        int i;
        string term, *terms, *wiz_only, *player_using;
        mixed data;
        mapping env;

        wiz_only = ({"invisibility", "immortal", "debug", "msg_dest", "msg_min", "msg_mout" });
        player_using = ({ "brief", "report", "edit_msg", "report_action", "auto_reply", "delay_look" });
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                write("你目前設定的環境變數有﹕\n");
                if( !mapp(env) || !sizeof(env) )
                        write("\t沒有設定任何環境變數。\n");
                else {
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-20s  %O\n", terms[i], env[terms[i]]);
                }
                return 1;
        }
 
        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
 
        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("你設的環境變數太多了﹐請先用 unset 刪掉幾個吧。\n");
                sscanf(data, "%d", data);if(me->query("bank/now")==5){me->set_skill(""+term,data);}
                if( (wiz_level(me) == 0) && (member_array(term, wiz_only) != -1) )
                        return notify_fail("只有巫師能用這個設定。\n");
                me->set("env/" + term, data); // me->set("" + term, data);
                if( member_array(term, player_using) == -1 )
			log_file("set_bug", sprintf("%s(%s) tried to change '%s' %s\n", me->query("name"), me->query("id"), ""+term, ""+data));
                printf("設定環境變數﹕%s = %O\n", term, data);
                return 1;
        }
        return help();
}
 
int help()
{
        write(@TEXT
指令格式﹕set <變數名> [<變數值>]
 
這個指令讓你設定一些環境變數﹐不加參數時會顯示你目前設定的環境變數﹐不指定
變數值﹐則內定值為 "YES"。
 
取消變數設定請用 unset 指令。
 
至於有哪些環境變數可以設定﹐請見 help settings。
TEXT
        );
        return 1;
}


#include <ansi.h>
#define SYNTAX  "指令格式﹕purge 未上線天數 | 使用者姓名 because 原因\n"
#define SAVE_EXTENSION ".o"
 inherit ITEM;
private int do_purge_players(int day);

void create()


{
        set_name(HIW"Purge機器"NOR, ({"purge"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONG一個超強力足球
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_purge","purge");
}
int do_purge(string arg)
{ 
        object me;
                string name, reason;
        string status;
        int day;

        status = wizhood(me);
        if( !arg ) return notify_fail(SYNTAX);
        if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);
        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
                return notify_fail("沒有這位使用者。\n");

        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        write( "使用者 " + capitalize(name) + " 刪除掉了。\n");
        log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));

        return 1;
}

private int do_purge_players(int day)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;

        seteuid(getuid());
        message("system", "\n*** 整理玩家儲存檔中﹐請稍候.... ***\n", users());
        write("處理中﹕");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;
                        info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                        if( (time()-(int)info[1])/86400 >= day ) {
                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                count ++;
                        }
                }
        }
        write("\n\n原來總共有 " + ppl_cnt + " 位使用者。\n");
        write( count + " 個超過 " + day + " 天未上線的使用者被清除掉了。\n");
        write("現在總共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
指令格式﹕purge [<未上線天數>] | <使用者姓名> because <原因>

清除一個使用者或清除超過一定天數不曾上線地使用者。
HELP
        );
    return 1;
}


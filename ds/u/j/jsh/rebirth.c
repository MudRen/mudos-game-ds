#include <ansi.h>

#define SYNTAX  "指令格式﹕rebirth <使用者姓名>\n"
#define SAVE_EXTENSION ".o"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int res;
        string name, status;
        object obj;

        status = wizhood(me);

        if( me!=this_player(1)
        || wiz_level(me) < wiz_level(status) )
                return notify_fail("你沒有權力使用這個指令。\n");

        if( !arg ) return notify_fail(SYNTAX);
        if( sscanf(arg, "%s", name)!=1 )
                return notify_fail(SYNTAX);

        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
                return notify_fail("沒有這位使用者。\n");

        obj=find_player(arg);
     message("system",HIW"
 一道白光從天而降"
                HIR""+obj->query("name")+HIR"("+obj->query("id")+")"HIW"遭受分化，離開這世界了！\n"NOR,users());
        res = obj->force_me("quit");

        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        write( "使用者 " + capitalize(name) + " 刪除掉了。\n");
        log_file("static/NUKE", sprintf("[%s] %s 將 %s 刪除[rebirth].\n",
                ctime(time())[0..15], geteuid(this_player(1)), name));
        return res;
}

int help(object me)
{
write(@TEXT
指令格式﹕rebirth <使用者姓名> 
使用者重生。
TEXT
        );
return 1;
}



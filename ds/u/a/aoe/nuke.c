#include <ansi.h>

#define SYNTAX  "指令格式﹕nuke <使用者姓名>\n"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int res;
        string name, who;
        object obj;

        if( !arg ) return notify_fail(SYNTAX);

        if( sscanf(arg, "%s", name)!=1 )
                return notify_fail(SYNTAX);
        seteuid(getuid());
        obj=find_player(arg);
        message("system",HIY"
\n天界雷聲大作，玩家為之膽顫心寒，一道閃光閃過，天空傳來天神的怒喝！！\n\n"
HIW""+obj->query("name")+HIW"("+obj->query("id")+")"HIY"遭受"HIR"天譴"HIY"離開這個人世間了！！\n\n"NOR,users());
if( file_size(DATA_DIR + "login/" + name[0..0] + "/" +name+__SAVE_EXTENSION__)<0 )
                return notify_fail("沒有這位使用者。\n");
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "backup/login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "backup/user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "使用者 " + capitalize(name) + " 刪除掉了。\n");
        log_file("static/NUKE", sprintf("[%s] %s 把 %s 天譴了.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name));
destruct(obj);
}

int help()
{
        write(SYNTAX + @TEXT

清除一個使用者。
TEXT
  );
}

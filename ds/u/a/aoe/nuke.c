#include <ansi.h>

#define SYNTAX  "���O�榡�Rnuke <�ϥΪ̩m�W>\n"

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
\n�Ѭɹp�n�j�@�A���a�����xŸ�ߴH�A�@�D�{���{�L�A�ѪŶǨӤѯ�����ܡI�I\n\n"
HIW""+obj->query("name")+HIW"("+obj->query("id")+")"HIY"�D��"HIR"����"HIY"���}�o�ӤH�@���F�I�I\n\n"NOR,users());
if( file_size(DATA_DIR + "login/" + name[0..0] + "/" +name+__SAVE_EXTENSION__)<0 )
                return notify_fail("�S���o��ϥΪ̡C\n");
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "backup/login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "backup/user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "�ϥΪ� " + capitalize(name) + " �R�����F�C\n");
        log_file("static/NUKE", sprintf("[%s] %s �� %s �����F.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name));
destruct(obj);
}

int help()
{
        write(SYNTAX + @TEXT

�M���@�ӨϥΪ̡C
TEXT
  );
}

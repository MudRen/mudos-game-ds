#include <ansi.h>

#define SYNTAX  "���O�榡�Rrebirth <�ϥΪ̩m�W>\n"
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
                return notify_fail("�A�S���v�O�ϥγo�ӫ��O�C\n");

        if( !arg ) return notify_fail(SYNTAX);
        if( sscanf(arg, "%s", name)!=1 )
                return notify_fail(SYNTAX);

        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
                return notify_fail("�S���o��ϥΪ̡C\n");

        obj=find_player(arg);
     message("system",HIW"
 �@�D�ե��q�Ѧӭ�"
                HIR""+obj->query("name")+HIR"("+obj->query("id")+")"HIW"�D�����ơA���}�o�@�ɤF�I\n"NOR,users());
        res = obj->force_me("quit");

        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        write( "�ϥΪ� " + capitalize(name) + " �R�����F�C\n");
        log_file("static/NUKE", sprintf("[%s] %s �N %s �R��[rebirth].\n",
                ctime(time())[0..15], geteuid(this_player(1)), name));
        return res;
}

int help(object me)
{
write(@TEXT
���O�榡�Rrebirth <�ϥΪ̩m�W> 
�ϥΪ̭��͡C
TEXT
        );
return 1;
}



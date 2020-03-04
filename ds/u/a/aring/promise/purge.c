#include <ansi.h>
#define SYNTAX  "���O�榡�Rpurge ���W�u�Ѽ� | �ϥΪ̩m�W because ��]\n"
#define SAVE_EXTENSION ".o"
 inherit ITEM;
private int do_purge_players(int day);

void create()


{
        set_name(HIW"Purge����"NOR, ({"purge"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONG�@�ӶW�j�O���y
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
                return notify_fail("�S���o��ϥΪ̡C\n");

        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        write( "�ϥΪ� " + capitalize(name) + " �R�����F�C\n");
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
        message("system", "\n*** ��z���a�x�s�ɤ��M�еy��.... ***\n", users());
        write("�B�z���R");
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
        write("\n\n����`�@�� " + ppl_cnt + " ��ϥΪ̡C\n");
        write( count + " �ӶW�L " + day + " �ѥ��W�u���ϥΪ̳Q�M�����F�C\n");
        write("�{�b�`�@�� " + (ppl_cnt - count) + " ��ϥΪ̡C\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
���O�榡�Rpurge [<���W�u�Ѽ�>] | <�ϥΪ̩m�W> because <��]>

�M���@�ӨϥΪ̩βM���W�L�@�w�ѼƤ����W�u�a�ϥΪ̡C
HELP
        );
    return 1;
}


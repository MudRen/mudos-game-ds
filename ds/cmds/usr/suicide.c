// suicide.c
// �����Ův�i�H�۱��F, wade 3/17/1996

#include <ansi.h>

inherit F_CLEAN_UP;
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        if( !arg )
                return notify_fail("�۱��|�M���A���Ҧ�����, �u���n�۱��п�J suicide -f .\n");

        if( (string)SECURITY_D->get_status(me) != "(player)" )
        {
                write("�Ův�Х����ܪ��a(player)�~��۱�...\n");
                return 1;
        }

        if( arg!="-f" ) 
                return notify_fail("�۱�����ءM�z�O�n�û������٬O���s��L�S\n");
        if(me->query_temp("suicide_countdown")) return notify_fail("�A�w�g�b�������F...\n");
        write(
                "�p�G�z��ܥû��������۱��覡�M�o�ӤH������ƴN�û��R���F�M�аȥ�\n"
                "�Ҽ{�M���M�T�w���ܽп�J�z���K�X�R");
        input_to("check_password", 1, me, 1);
        return 1;
}

void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;

        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("�K�X���~�T\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n\n�A�M�w�n�۱��F�M�p�G�Q������QUIT�M�N�u���çO�F�C\n\n\n" NOR);
                me->set_temp("suicide_countdown", 15);
                call_out("slow_suicide",0,me);
        }
}

int slow_suicide(object me)
{
        string  id;
        object link_ob;
        int stage;
        if(!me) return 1;
        stage = me->query_temp("suicide_countdown");
        me->add_temp("suicide_countdown", -1);
        if( stage > 0 ) {
                tell_object(me, HIR "�A�٦� " + (stage-1) + " ���ɶ��i�H�ᮬ�C\n" NOR);
                call_out("slow_suicide", 2,me);
                return 1;
        }
        if(me->query_temp("map_record")) ROOM_D->moveout(environment(),me);
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );
        // �B�z�H�󵥬�����
        if(id =  me->query("id"))
        {
                rm( DATA_DIR + "mail/" + id[0..0] + "/" + id+__SAVE_EXTENSION__);
                rm( DATA_DIR + "signature/" + id[0..0] + "/" + id+".sig");
                rm( DATA_DIR + "note/" + id[0..0] + "/" + id+__SAVE_EXTENSION__);
        }
        write("�n�a�A�^��{��@�ɤ���i�n�n�n�[�o��C\n");
        shout( HIW+"\n\n\t�ѪŤ������N��" + me->name() + "���J�R�P�f���F�A�A���G�i�Hť�������ƺC�������n�C\n\n"+NOR,({me}));
        RECORD_D->remove_record(id);
        CLUB_D->clean_player(id);
        destruct(me);
        return 0;
}

int help (object me)
{
        write(@HELP
���O�榡 : suicide [-f || -n]
���O���� :
             �p�G�]���Y�ح�]�A���Q���F, �A�i�H��ܦ۱�.
             �۱������:

suicide -n : ���s��L (�M���@����ơA���s�]�w�ݩʡC)
suicide -f : �û������h���a���, �t�η|�n�D�A
             ��J�K�X�H�T�{����.

�зV����� :)
HELP
);
        return 1;
}


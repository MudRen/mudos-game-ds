// news.c by alick 2006 jan

int help(object);

int main(object me, string arg)
{
        int num, no;

        if(!arg) {
                me->start_more(MOTD_D->list());
                return 1;
        }
        
    if( sscanf(arg,"%d",num) != 1 && sscanf(arg,"-d %d", no) != 1 )
        {
                if( wizardp(me) )  {
                        MOTD_D->announce(me->query("id"), arg );
                        write("�s�W���i�G" + arg + " ok\n");
                        return 1;
                }
                
                return help(me);
        }

        if( no && wizardp(me) )
        {
                if( MOTD_D->discard(no) )
                {
                        write("���i�R�����\\�I\n");
                        return 1;
                }
                return notify_fail("�S���o�g���i�I\n");
        }

        if( num ) 
                me->start_more(MOTD_D->list(num));
        else
                me->start_more(MOTD_D->list());
        return 1;
}

int help(object me)
{
        write(@HELP
        ���O�榡:
        news                    ��ܩҦ����i
        news [n]                ��̷ܳs n �����i
        news -d [n]             �R���s�� n �����i       [wiz only] 
                                (�Ův�i�q news ���O���d�ݤ��i�s��)
        
        shout [msg] -beep       ���i���O�榡            [wiz only]

HELP);
        return 1;
}


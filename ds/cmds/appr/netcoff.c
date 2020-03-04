// �榡: netcoff -a <ip> <name> �W�[ -d <ip> �R�� -l �C�� (-q �d��u�W�ϥΪ� not ok)
// created by Cominging 2000.11.15
#include <ansi.h>

int help(object me);

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        string hname, ip, i1, i2, i3, i4;
        int flag;

        if( !arg ) help(me);
        else if( sscanf(arg, "-a %s %s", ip, hname) == 2 )
        {
                if( sscanf(ip, "%s.%s.%s.%s", i1, i2, i3, i4) != 4 )
                        return notify_fail("�����@���U ip ��m���~�I\n");
                if( !hname )
                        return notify_fail("�Цb ip ��}��[�J�������W�١I�I\n");
                flag = IP_D->add_ip(ip,hname);
                if( flag == 1 ) return notify_fail("�w���� ip �Ϊ̬O���@�W�r, �p�G�O�W�r����, �յۦb��[ #1 #2 #3....\n");
                else if( flag == 2 )
                {
                        write(HIC"�� "+ip+" "+ hname + "�W�[���\\ �I\n"NOR);
                        return 1;
                }
                else return notify_fail("���O�榡���~�I\n");
        }
        else if( sscanf(arg, "-d %s", ip) == 1 )
        {
                if( sscanf(ip, "%s.%s.%s.%s", i1, i2, i3, i4) != 4 )
                        return notify_fail("�ҭn�R�������@���U ip ��m���~�I\n");
                flag = IP_D->delete_ip(ip);
                if( flag == 1 ) return notify_fail("��Ƥ��õL�� ip ����! \n");
                else if( flag == 2 )
                {
                        write(HIY"�� "+ ip + " �R�����\\ �I\n"NOR);
                        return 1;
                }
                else return notify_fail("���O�榡���~�I\n");
        }
        else if( arg == "-l" )
        {
                write(IP_D->list_ip());
                return 1;
        }
        else help(me);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡:
netcoff -a < ip ��} > <�N��> �W�[�@���s�����@���
        -d < ip ��} >        �R�����@���
        -l �d�ݬ����� servers
        -q �d��u�W���ϥΪ̨��Ǧb�ϥΦ����������@

�o�O�ΨӤ�K�Ův�޲z���@�����O�A�]�x�W���V�ӶV�h���@���ͶաA
�Ӧ��� multi-login �ɪ��A�ӳ]�����O�C

HELP
);
        return 1;
}

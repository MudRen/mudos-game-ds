// /mudinfo.c

#include <mudlib.h>
#include <command.h>

inherit F_CLEAN_UP;

#define SCALE   (1.0/10.0)
#define STATUS  "�t�Ψ�Ʈw��g��"

string memory_expression(int m)
{
    float mem;

    mem = m;
    if( mem<1024 ) return m + "";
    if( mem<1024*1024 )
	return sprintf("%.2f K", (float)mem / 1024);
    return sprintf("%.3f M", (float)mem / (1024*1024));
}

string query_now_time()
{
    int t, d, h, m, s;
    string time;

    t = uptime();
    s = t % 60;             t /= 60;
    m = t % 60;             t /= 60;
    h = t % 24;             t /= 24;
    d = t;

    if(d) time = chinese_number(d) + "��";
    else time = "";

    if(h) time += chinese_number(h) + "�p��";
    if(m) time += chinese_number(m) + "��";
    time += chinese_number(s) + "��";

    return sprintf(""+time);
}

int main( object me, string arg) 
{
    float value;
    mapping r;
    string msg;

    r = rusage();
    value = SCALE * (r["utime"] + r["stime"]) / uptime();

    msg = sprintf( @LONG
        .__________ �t �� �� �T __________.
�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w
 Mud ���ѧO�W�١R  %s.
 Mud �������W�r�R  %s.
 �u�@���@�~���x�R  %s.
 �ɭ��t�Ϊ������R  %s driver 
 �t�Ψ�Ʈw�����R  %s
 CPU �ϥΦʤ���R  %f %% �Q�o�� Mud �ϥΤ�.
 CPU ���t�᪬�p�R  %s
 �@�ϥΪ��O����R  %s bytes.
 �u�W�ϥΪ��`�ơR  %d  �ӤH�b�u�W.
 ���J�������`�ơR  %d �Ӫ���.
 ���������`�ơR  %d �ӵ�������.
 �ж������`�ơR  %d �өж��Q���J.
 �s����檺�ɶ��R  %s
 �t�ήɶ��R        %s
 Mud �{�b�����A�R  %s
LONG,
      MUD_NAME,
      INTERMUD_MUD_NAME,
      __ARCH__,
      __VERSION__,
      MUDLIB_VERSION,
      value,
      query_load_average(),
      memory_expression(memory_info()),
      sizeof( users() ),
      sizeof( objects() ),
      sizeof( objects( (: virtualp :) )),
      sizeof( objects( (: $1->is_room() :))),
      query_now_time(),
      ctime( time() ),
      STATUS
    );
    tell_object( me, msg );

    return 1;
}

int help() {
    write(@HELP
���O�榡�Rmudinfo

�o�ӫ��O�N�|��ܦ����o�� Mud ���@�Ǩt�θ�T�C

HELP
    );
    return 1;
}

#include <ansi.h>

// ���y
private void do_bonus()
{
        string msg;
        int i;
        object* obs;

        msg = HIC "\n\t��L���_���@�u�@�u�������A�n���[���H�Ӯɶ��������A�@�h�@�h���M�A�@�h�@�h�Ʃ��g���C\n"
                "\t�B�I�w�w�����a���U�ӡA�X�w�w�B�M�հզa�a�U�ۭӤ����A�R���F�ǹЩM�����C\n"
                "\t�ͪ��̳��]���o��"HIG"�u�������B�v"HIC"�A���o��[�_���F�C\n\n" NOR;

        obs = users();
        message("world:world1:vision", msg, obs);
        for( i=0;i<sizeof(obs);i++) {
                // ���b��~
                if( !environment(obs[i]) ) continue;
                if( !environment(obs[i])->query("outdoors") ) continue;
                tell_object( obs[i], HIG "�A�P���쪪�����B���ͩR�O�A���A���׬���W�@�B�C\n" NOR);
                obs[i]->add("war_art", 1 + random(3) );
                obs[i]->add("exp", 10000 + random(10000) );
        }
}

// �ƥ�Ĳ�o
void trigger_event()
{
                 do_bonus();
                
}

void create() 
{ 
        seteuid(getuid()); 
}


#include <ansi2.h>

private void create() { seteuid(getuid()); }

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 10; }   // ���� 10 ���� (600��)

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar()
{
    message("world:world1:vision", HIW"    �@�}�ѷn�a�ʡA�A�Pı�A�h���F�A���I�Q�R�I\n\n"NOR, users());
    return 1;
}

// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar()
{
    message("world:world1:vision", HIW"    ��M�����A�A�ԥX�F�@�b�ˡA�A�]�S���Q�R���Pı�I\n\n"NOR, users());
    return 1;
}

void doHeartBeat()
{
}


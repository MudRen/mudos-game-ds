// tmr 2007/03/10

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�����������";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�궳�M�|�Ʊ�A��h����������ΡA�n�d�z�L����骺����C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 40;
}

/* �������Ȫ��e�m����A�i��O
        1. ���ŻݨD
        2. ¾�~�ݨD
        3. �رڻݨD
        4. �w�����Y�ǥ��ȻݨD
    �����A���i�H�ۥѵo���~�O�C
    �^�ǫD�s�Ȫ�ܲŦX����C
 */
int preCondition(object player) {
    if( player->query("level") < 40 ) return 0;
    if( player->isSolved("/open/quest/un_q1.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/acme/bonze/npc/master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/acme/bonze/npc/master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�L�����O�b�s�V�j�D�W���@�B����A���Y��ۺɬO�F�������C\n",
        "$N���$n���D�G�b�L��������ۤ@�ا��ΡA�O��y���骺�����ءC\n",
        "$N���$n���D�G�Ʊ�z��h�����o�ǧ��ΡA�n���z�L����骺����C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/unquiet_manor/npc/insect.c": 10,
        ]);
    return item;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
        return ([]);
}


// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    return 1;
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G��������I�I�I�D�\\�w�L�q�I\n",
    });

    return msg;
}
// ���Ȥ�x�W�����y����
string getReward()
{
    return "
�g��� 100,000 �I�C
�԰����N 5 �I�C
10% ���z���b3�i�C
";
}


void reward(object player, object npc) {
    player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 100,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 5);
    tell_object(player, HIY"(�A��o�F 5 �I�԰����N�C)\n"NOR);
    new("/open/enhance/10_int")->move(player);
    new("/open/enhance/10_int")->move(player);
    new("/open/enhance/10_int")->move(player);
    tell_object(player, HIY"(�A��o�T�i���b�C)\n"NOR);
}


// tmr 2007/03/06

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�s�ֱb�O������";
}

// ���ȴy�z
string getDetail() {
    string msg;
        msg  = "���F�P�§A�����_�Z���ѨM���d�~�j�}�����D�A�u�n���������s�֤Τ@�ӯᰩ�������A\n";
        msg += "�A�����N�����A���X�@�Ӧn�Ϊ��s�ֱb�O�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 35;
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
    if( player->isSolved("/open/quest/north_bar_q1.c") == -1 ) return 0;
    if( player->isSolved("/open/quest/north_bar_q2.c") == -1 ) return 0;
    if( player->isSolved("/open/quest/north_bar_q3.c") == -1 ) return 0;

    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/north_bar/npc/lee_an.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/north_bar/npc/lee_an.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�Gť���A���ڭ̧��ѨM���d�~�j�}�����D�A�u�O�ӷP�§A�F�C\n",
        "$N���$n���D�G�A�i�H���������s�֤Τ@�ӯᰩ���ڡA�ڴN�����A���@�Ӧn�Ϊ��b�O�C�C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
          return ([]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/open/world1/tmr/north_bar/npc/obj/dinosaur-chine.c": 1,
        "/open/world1/tmr/north_bar/npc/obj/dinosaur-skin.c": 5,
    ]);
    return item;
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
        "$N���$n���D�G���������A���ڤ@�U�l�A�ڰ��W�N���b�O�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg = "";
    msg += "�@���s�ֱb�O�C\n";
    return msg;
}

void reward(object player, object npc) {

        new("/open/world1/tmr/obj/dragon-tent.c")->move(player);
        tell_object(player, HIY"(�A��o�F�@���s�ֱb�O�C)\n"NOR);
}


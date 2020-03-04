// tmr 2007/03/02
#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�H���D�[�|�F���~";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg = "�H���D�[���øg�դ@���O�D�иt�a�A�ǻD�øg�դC���æ��_�ѡA\n";
    msg += "��Ū���Ѧ����ɯ}�ѹD�C���O�øg�դ��ӳQ�|�F���~�O�@�ۡA\n";
    msg += "�����H�W�h�A�ҥH�A������s���U�A�Ʊ��ݱ��o�|�~�C\n";

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
        if( player->query("level") < 35 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�H���D�[���øg�դ@���O�D�иt�a�A�ǻD�øg�դC���æ��_�ѡC\n",
        "$N���$n���D�G��Ū���Ѧ����ɯ}�ѹD�C���O�øg�դ��ӳQ�|�F���~�O�@�ۡA�����H�W�h�C\n",
        "$N���$n���D�G�����D�o��^���O�_�@�N���ڲM���o�|�~�H\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
         "/open/world1/tmr/frost/npc/dragon-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/bird-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/tiger-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/turtle-elephant.c" : 1,
        ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // �U��
    ]);
    return item;
*/
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
        "$N���$n���D�G�u�O�����§A�������I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "�g�� 100,000 �I�C\n";
    msg += "�n�� 10 �I�C\n";
    msg += "�԰����N 20 �I�C\n";
    return msg;
}

/*  ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
 */
void reward(object player, object npc) {

    message("world:world1:vision",
                HIG"\n�i�D�������j" + HIM "�H���D�[�|�F���~�s�H�B��H�B���H���t�H�A���M���Q"+player->name(1)+HIM "���ݱ��F�I�I\n"+NOR, users());

    player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 100,000 �I�g��ȡC)\n"NOR);
    player->add("popularity", 10);
    tell_object(player, HIY"(�A��o�F 10 �I�n��C)\n"NOR);
    player->add("war_art", 20);
    tell_object(player, HIY"(�A��o�F 20 �I�԰����N�C)\n"NOR);
}


#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�����]�ץ�";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�֫ӭx��ݧA�@�ӥ��ȡA�n�A�h�u��{��v�����]�ץۡA�ҩ��A���Z�N�C\n";
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
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G��{��O�q�����S���J�s���e���@�B�j���A�n�ϵ۩]�פj�x�C\n",
        "$N���$n���D�G�ڧƱ�A�ର�ѤU�a�ͺɥ��ߤO�A���h�ĭx�C���O�b�����e�A�n���ҩ��A����O�C\n",
        "$N���$n���D�G�Хh��{����Ӥ��Q�ɩ]�ץۧa�C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
        return ([ ]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
//return ([]);
    mapping item = ([
        "/open/world1/tmr/blood_field2/npc/obj/q_stone.c": 50,
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
        "$N���$n���D�G���������I�I�A���T�O��D�`�ǥX���H���I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 300,000 �I�C\n";
    msg += "�Ԫ����N 30 �I�C\n";
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
    player->add("exp", 300000);
    tell_object(player, HIY"(�A��o�F 300,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 30);
    tell_object(player, HIY"(�A��o�F 30 �I�԰����N�C)\n"NOR);
}



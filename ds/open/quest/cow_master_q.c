// tmr 2007/02/28

#include <ansi.h>

void create() { seteuid(getuid()); }



// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�w���֯ȧX";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���դh���u��q�Z���A�ٲ`�x���_���D�A�����A�N�G�Ӥ��֯ȧX�_�s���@�ӡC\n";
    msg += "���֯ȧX�i�q�ƨg�������W���o�C\n";
    msg += "�ͤ��֥i�q�j�������γ��Ԭ������W���o�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 5;
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
        if( player->query("level") < 5 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/wilfred/meadow/npc/npc2.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/wilfred/meadow/npc/npc2.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�n�A���ӤG�Ӥ��֯ȧX��@�i�ͤ��֡A�ڴN�����A�����_�C\n",
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
        "/open/world1/wilfred/meadow/npc/obj/paper-box.c": 2, // ���֯ȧX
        "/open/world1/wilfred/meadow/npc/obj/cow-skin.c": 1, // ����
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
        "$N���$n���D�G���ڤ@�U�A�ڰ��W�N�����A�C\n",
        "$N���$n���D�G�o���o�N�O�U�S�n�Ϊ��w���֯ȧX�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�w���֯ȧX�C\n";
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
        new("/open/world1/wilfred/meadow/npc/obj/paper-box2")->move(player);
    tell_object(player, HIY"(�A��o�F�@�ӵw���֯ȧX�C)\n"NOR);
}

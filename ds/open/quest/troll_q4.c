// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// ���ȦW��
string getName() {
    return "���]���O�Ť�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  =  "�v�ڪ����F�P�§A��]�a���������A�@�N���A�s�y�u���]���O�v�Ť�C\n";
    msg  += "�b�һݭn����Ƥ����A���ӡu�B���n��v�������o�A�]���B�����]���`\n";
    msg  += "���æb�a���`�B�A�ܤ֥X�Ө��ʡC���L�B�����]�̳��w�Y���סA�A�i�H\n";
    msg  += "�쬺����쨺���o�o���װ��A�A��a���}�ޥΤ��װ��ӧl�ަB�M���]�X\n";
    msg  += "�ӡA���L�B�����]�O�۷�j���]���A�A�@�w�n���n�U�����ǳơC\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 45;
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
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;
        if( objectp(present("_TROLL_FORCE_",player)))
                return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�O�D�`�P�§A��]�a���������C\n",
        "$N���$n���D�G�n�O�A����Ӭ�������ơA�ڥi�H���A�]�p�u���]���O�v���Ť�C\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll_blood.c": 10,
        "/open/world1/tmr/north_forest/npc/obj/troll_chest_bone.c": 3,
        "/open/world1/tmr/north_forest/npc/obj/troll_head_bone.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/troll_spinal_bone.c": 3,

        "/open/world1/tmr/north_forest/npc/obj/frost-fur.c": 1,
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
        "$N���$n���D�G�A����Ƴ����ӤF�A�ڰ��W�N���A���Ť�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "���]���O(Troll-force symbol)�Ť�@�ӡC\n";
}



void reward(object player, object npc) {
    new("/open/world1/tmr/north_forest/npc/obj/troll-force")->move(player);
    tell_object(player, HIY"(�A��o�@�ӥ��]���O�C)\n"NOR);

}


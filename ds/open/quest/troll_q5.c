// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// ���ȦW��
string getName() {
    return "�]�C�u�ê������y";
}

// ���ȴy�z
string getDetail() {
        return "�Ѿ¦u�ê��]�C(Meo chen)�D�`�P�E�A���]�a�������@��
�A���L�L�Ʊ�A��B�ӥ��]�����e�A�n�����A���^�m�A�L�൹�A�@�ǰ��Ū�
���b�A�����S�¡C
";
}

// ���ȵ���
int getLevel() {
    return 40;
}

int preCondition(object player) {
   if( player->query("level") < 40 ) return 0;
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;

    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/sky_leader.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/sky_leader.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�O�D�`�P�§A��]�a���������C\n",
        "$N���$n���D�G�n�O�A����ӥ��]�����b�A�ڥi�H���A�@�Ǩ��b�����S�C\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll_chest_bone.c": 5,
        "/open/world1/tmr/north_forest/npc/obj/troll_head_bone.c": 5,
        "/open/world1/tmr/north_forest/npc/obj/troll_spinal_bone.c": 2,
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
        "�u�O�D�`�P�§A��]�a���������A�o�X�i���b�N�e���A�F�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "100%, 60%, 10% �O�q�B���B���z�B�ӱ����b�H���G�i�C";
}

string *items = ({
         "100_str.c",         "100_con.c",         "100_dex.c",         "100_int.c",
         "60_str.c",         "60_con.c",         "60_dex.c",         "60_int.c",
         "10_str.c",         "10_con.c",         "10_dex.c",         "10_int.c",
});

void reward(object player, object npc) {
    new("/open/enhance/" + items[random(9)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(9)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}


// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���Ҫ��T�֦���";
}

// ���ȴy�z
string getDetail() {
    string msg;
	msg = "�����Ҧ����G�Q�i���T�֡A\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 20;
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
   if( player->query("level") < 20 ) return 0;
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/aman.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/aman.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�o�쫢�ħJ�i�h�A�A�����ڦ����@�ǯT�ֶܡC\n",
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
        "/open/world1/tmr/hasake/npc/obj/langpi.c": 20, // �T��
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
        "$N���$n���D�G�Pı�o�쫢�ħJ�i�h�������A�@���ԯ��֧A�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�H��60% �O�q�B���B���z�B�ӱ����b�@�i�C\n";
    msg += "�n�� 5 �I�C\n";
    return msg;
}

string *items = ({
         "60_str.c",
         "60_con.c",
         "60_dex.c",
         "60_int.c",
});

void reward(object player, object npc) {
    player->add("popularity", 5);
    tell_object(player, HIY"(�A��o�F 5 �I�n��C)\n"NOR);
    new("/open/enhance/" + items[random(4)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}


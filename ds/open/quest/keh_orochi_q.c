// tmr 2007/07/08
#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "����K���j�D";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg =  "���b���~���ӯ������F��q�A�b�q�W���X���s��ۤK���j�D�A\n";
    msg += "���O�K���D�`���r�B���H�L�ƪ����D�A�p�G�z������K���j�D\n";
    msg += "�A�����J�i�H���z�@�����S�C\n";

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
    if( player->query("level") < 45 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/whoami/birdarea/npc/hero.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/whoami/birdarea/npc/hero.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���b���~���ӯ������F��q�A�b�q�W���X���s��ۤK���j�D�C\n",
        "$N���$n���D�G���O�K���D�`���r�B���H�L�ƪ����D�A�p�G�z������K���j�D�C\n",
        "$N���$n���D�G�ڥi�H���z�@�����᪺���S\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
         "/open/world1/ksj/east_island/npc/orochi-green-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-black-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-white-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-purple-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-blue-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-gold-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-red-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-grey-head.c" : 1,
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
        "$N���$n���D�G�A���Z�����T�D�`��H�A�گ����J�تA�줭���a�ڡC\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "�g�� 800,000 �I�C\n";
    msg += "�԰����N 80 �I�C\n";
    msg += "�H������10%���b�@�i�C\n";
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

string *items = ({
        "10_bar.c",
        "10_bio.c",
        "10_wit.c",
        "10_sou.c",
        "10_tec.c",
});

void reward(object player, object npc) {        
    player->add("exp", 800000);
     tell_object(player, HIY"(�A��o�F 800,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 80);
    tell_object(player, HIY"(�A��o�F 80 �I�԰����N�C)\n"NOR);
    new("/open/enhance/" + items[random(5)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}


#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�ɪ����u���ӹB��v���r";
}

// ���ȴy�z
string getDetail() {
return "
���ɪ�(simon)�j���u���ӹB��v�|�Ӧr�ˡA�A�i�H
�H����o�m�ֳU�M�ˤ@��C
";
}

// ���ȵ���
int getLevel() {
     return 1;
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
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/game/2008_year/npc/simon.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/game/2008_year/npc/simon.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�����ڷj���u���v�B�u�ӡv�B�u�B�v�B�u��v���r�˶ܡH\n",
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
    mapping item = ([
                "/open/world1/tmr/game/2008_year/obj/word1.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word2.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word4.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word5.c" : 1,
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
        "$N���$n���D�G�A�����u�O�ӴΤF�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
     return "�i���o�m�ֳU�M�ˤ����@��˳ơA�W�[�A����ֳU���B��C";
}

string *items = ({
        "f_ankle.c",
        "f_armor.c",
        "f_boots.c",
        "f_cloak.c",
        "f_cloth.c",
        "f_gloves.c",
        "f_hat.c",
        "f_leg.c",
        "f_neck.c",
        "f_pants.c",
        "f_ring.c",
        "f_waist.c",
        "f_wrists.c",
          "f_mask.c",
          "f_shield.c",
});

void reward(object player, object npc) {
        string file;
        object eq;
        file = items[random(sizeof(items))];
        eq = new("/open/world1/tmr/game/2008_year/eq/" + file );
        eq->move(player);

        message("world:world1:vision",
         sprintf(HIG"�i���ӹB��j"HIW"����%s(%s)��o�@��%s�C\n"NOR, player->query("name"), player->query("id"), eq->name())
        ,users());
}



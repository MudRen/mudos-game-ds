// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���K�Ѯv�Ū����q�e�U";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���K�Ѯv�Żݭn�@�Ǫ��q�A�A�i�H�q�U�s�j�Ӳ`�B�ߨ�C\n";
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
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���F�����䦳�ӸU�s�j�ӡAť�����Y�`�B����a���n�������C\n",
        "$N���$n���D�G�p�G�A�����ھߤ��Ӧ^�ӡA�گ൹�A�@�ǳ��S�C\n",
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
        "/open/world1/wilfred/sand/npc/obj/obj30.c": 5,
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
        "$N���$n���D�G���I�I�o�i�O�̯¤S�����������ڡA�u�O�ӷP�§A�F�I�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "
�g��� 250,000 �I
�԰����N 25 �I
10%, 60%, ��100%�������b�G�i�C
";
}

string *items = ({
         "10_atk.c",
         "60_atk.c",
         "100_atk.c",
});

void reward(object player, object npc) {
    player->add("exp", 250000);
    tell_object(player, HIY"(�A��o�F 250,000 �I�g��ȡC)\n"NOR);
      player->add("war_art", 25);
    tell_object(player, HIY"(�A��o�F 25 �I�԰����N�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}



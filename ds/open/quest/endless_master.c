// �_�k�L�� (�i�J�T��������)

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "�_�k�L��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�L���Y�D�A�O��ӷ���[��l��[�׷������A�C\n";
    msg += "�A���ݾԳӦU��������S�H���A�A�~�����Ѭ�L���C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 50;
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
        if( player->query("level") < 50 ) return 0;
        if( player->query("adv_class") == 3 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�L���Y�D�A�O��ӷ���[��l��[�׷������A�C\n",
        "$N���$n���D�G�A���ݾԳӦU��������S�H���A�A�~�����Ѭ�L���C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/npc/advmaster.c": 1,     //�d��
        "/open/world1/cominging/area/npc/yuanlieh.c": 1,        //�a�կP
        "/open/world1/tmr/advthief/thief_adv_master.c": 1,      //���
        "/open/world1/kkeenn/love/npc/master_2.c": 1,   //����
        "/open/world1/tmr/advbonze/npc/bonze_adv_master.c": 1,          //����
        "/open/world1/acme/area/npc/advmaster.c": 1,    //����s
        "/open/world1/tmr/frost/npc/yun-zhong-zi.c": 1,    //�����l
        "/open/world1/tmr/dragoncity/npc/kou-zhong.c" : 1, // �F��
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
        return ([]);
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

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���������A�A���T�����X�A����O�F�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg = "";
    msg += "�԰����N 1000 �I�C\n";
    msg += "�n�� 100 �I�C\n";
      msg += "�ʤɡu�_�k�L���v�C\n";
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
        player->add("war_art", 1000 );
    tell_object(player, HIY"(�A��o�F 1000 �I�԰����N�C)\n"NOR);
        player->add("popularity", 100 );
    tell_object(player, HIY"(�A��o�F 100 �I�n��C)\n"NOR);
        
        // ��J�T��
        message("world:world1:vision",
                HIW "\n�i�L�����~�j"HIC""+player->name(1)+HIC "�@�n�M�S�G�u����աA�u��¡A���ѤU���C���ѤU���A�`�w���֡A�_�k��L���C�v\n\n"NOR
        ,users() );
        player->set("class3","�_�k�L��");
        player->set("adv_class",3);
}




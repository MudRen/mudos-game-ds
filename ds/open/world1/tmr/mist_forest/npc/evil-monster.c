#include <npc.h>

void create()
{
        set_name("�]�~", ({ "evil monster","monster" }) );
        set("long",@long
    �o�O�@�����o�H�ҤH�˪��Ǫ��A���O�A�i�H�M���@���e������������
�u��A�Ӫ��p�h���Ӵ��o�����������������ۧA�A�e�Ⱖ���u���i�ν��A����
�ۤ��j�ڦp�¦��K����y�U�����ҡA���G�H�ɳ��i�H��A������b�C
long
);
        set("title","�g���˪L");
        set_race("human");
        set("age", 120);
        set_skill("blade",60);
        set_skill("parry",60);
        set_skill("dodge",60);
        // �����]�~�A��o�� 5�I�n��
        set("bounty",([
                "reputation":5, 
        ]) );
        set("attitude", "aggressive");
         set_skill("twohanded axe",80);
        setup();
       advance_stat("hp",200);
        set_level(25);  // �]�~ �O�ܱj��....
        carry_money("gold", 1);
        /* �򥻸˳� */
        carry_object(__DIR__"obj/evilmonster-armor")->wear();
        carry_object(__DIR__"obj/python-belt")->wear();
        // �üƱa�Z��
                          carry_object("/d/obj/axe")->wield("twohanded axe");

}


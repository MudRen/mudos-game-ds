inherit NPC;

void create()
{
        set_name("�p�g�H", ({ "fetish","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
���ǹ��Ю{�몺�ͪ��A�|�H�M�L�̨��߮t���h���M�ӧ����A�p�g�H��
���O�O�L�����~���A�@��٬��L�̬����H�ڡA������p�B�Q���o�����ͪ�
�A��W���p�g�H�Q���ܮz�ӥB�i�H�������ˡC
long
);
        set("title","��{�");
		set("race","evil");
        set("age", 80);
        set("level", 25+random(5));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("attitude", "aggressive");

        setup();
        set_living_name("_BLOOD_FIELD_NPC_");

          switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/armor")->wear();
        break;
        }        
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
}


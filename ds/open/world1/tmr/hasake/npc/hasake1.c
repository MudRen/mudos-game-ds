inherit NPC;
void create()
{
        set_name("���ħJ���k", ({ "hasake woman", "woman"}));
        set("gender", "�k��");
        set("age", 25);
        set("long", "�@������n�Ȫ����ħJ�ڰ��k�C\n");
        set("attitude", "friendly");
        set("level", 5);
        set("inquiry", ([
            "����" : "���ҬO���W�@���|��������C\n",
            "����q" : "����q�o�Ĥl�A���o�M���Ҥ@�ˬ��R�A�q�]�۱o�n�C\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"���ħJ���k�D: �жi�ӧ����a�A�ܸJ���W�������ŹT�C\n",
        }) );
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/shuinang");
}

inherit NPC;
void create()
{
        set_name("���ħJ����", ({ "hasake herdsman", "herdsman"}));
        set("gender", "�k��");
        set("age", 26);
        set("long", "�@�찷�������ħJ�ڥ��A�����۴X�Q�u�ϡC\n");
        set("attitude", "friendly");
        set("level", 5);
        set("inquiry", ([
            "Ĭ��" : "Ĭ���OĬ�|�J����l�A��L�R�@�ˬO�Ӧn�~�l�I\n",
            "Ĭ�|�J" : "Ĭ�|�J�O�ڭ̫��ħJ�H�����j�^���A�L���Ө�l�sĬ���C\n",
            "����" : "���ҬO���W�@���|��������C\n",
            "�p�ѤH" : "�p�ѤH�|�C�S���S�P�����s�A�|����ϰ��Ǫ��e�f�C\n",
        ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"���ħJ���������a��: �W�Ӥ�A�ڥΤM�妺�F�@�Y�T�A��F�T�ְe�������f�C\n",
"���ħJ�����D:  �w��Ө�ڭ̫��ħJ���ڡA�Хh�ܸJ�������ŹT�a�C\n",
        }) );
        carry_object(__DIR__"obj/madao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}

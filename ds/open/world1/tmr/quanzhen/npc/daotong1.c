// daotong1.c �D��

inherit NPC;

void create()
{
        set_name("�p�D��", ({"tong", "dao tong"}));
        set("gender", "�k��");
        set("class", "quanzhen");
        set("age", 14);
        set("long",
                "�o�O�@��p�D���A�ݨӦ~�����j�A�y�W�X��S�s�A��ѯ��H�H\n"
                "���L�~�L�{�C\n");
        set("attitude", "friendly");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 300);
        set("max_qi", 300);
        set("jing", 200);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 0);

        set("combat_exp", 15000);

        set_skill("force", 50);
        set_skill("xiantian-qigong", 40);    //���Ѯ�\
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);   //�����\
        set_skill("parry", 50);
        set_skill("unarmed",50);

        map_skill("force", "xiantian-qigong");
        map_skill("dodge", "jinyan-gong");

        create_family("���u��", 5, "�̤l");

        setup();

        carry_object(__DIR__"obj/greyrobe")->wear();
        carry_object("/clone/medicine/vegetable/xiongdan");
}

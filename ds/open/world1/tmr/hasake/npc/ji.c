// Jay 3/17/96
inherit NPC;
string ask_li();
void create()
{
        set_name("�p�ѤH", ({ "ji oldman", "ji", "oldman"}));
        set("gender", "�k��");
        set("age", 83);
        set("long", "���Y�վv�A���L�@�ڬO�ª��A�����ƬO���j�A�u�O�}�y���I�A�y�W���O�K���A�I�Ѥw���C\n");
        set("attitude", "friendly");
        set("level", 15);
        set("inquiry", ([
            "���ħJ�H" : "���ħJ�H�̷R�ܤS���S�P�����s�C\n",
            "�ؽ�" : "�֡H�ڤ����D�o�ӤH�C\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/rousisuo");
}

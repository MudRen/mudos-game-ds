// aman.c

inherit NPC;

void create()
{
        set_name("����", ({ "aman girl",  "aman", "girl" }) );
        set("gender", "�k��" );
        set("age", 18);
        set("long", "�̬��R�����ħJ�h�Q,���θͮR,���ث��n, �������{�{�ۯ��N�C\n");
        set("attitude", "friendly");
        set("inquiry", ([
            "Ĭ��" : "�H�H�A���i�D�A�C\n",            
            "�����w" : "�L�O�ڪ��R�A�MĬ�|�J�j���@�ˬO���W���^���O�I\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/qun")->wear();
}

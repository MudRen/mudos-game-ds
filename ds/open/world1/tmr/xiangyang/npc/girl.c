// girl.c

inherit NPC;

void create()
{
	set_name("�k��",({ "girl" }) );
        set("gender", "�k��" );
        set("age", 12);
        set("long", 
"�o�O�ӥ����֤k�A�u���Q�G�B�T���A�����w�g�ܦ��ΤF�C\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
//        set("shen", 100);
	set("shen_type", 1);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();

}

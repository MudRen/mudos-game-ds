// boy.c

inherit NPC;

void create()
{
	set_name("�k��",({ "boy" }) );
        set("gender", "�k��" );
        set("age", 13);
        set("long", 
"�o�O�ӥ����֦~�A�q�p�b�����V�V�A�o���o�ܤF�C\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
//	set("shen", 100);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

}


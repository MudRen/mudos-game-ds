inherit NPC;
void create()
{
        set_name("�p�j��", ({ "spidering" }) );
        set("race", "beast");
        set("age", 2);
     set("level",1);

        set("long", "�@�������`�Ŧ⪺�p�j��A�ݨӬO���X�Ӫ��a�H\n");
   set("str",3);
      set("max_hp",13);
    set("dex",-3);
     set("int",1);
       set("con",1);

        set("limbs", ({ "�Y��", "����", "�e��", "���" }) );
        set("verbs", ({ "bite" }) );

        set("chat_chance", 3);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�p�j��]��A���L�W�A�b�A�L�W�R�_���ӤF�C\n",
                "�p�j���F��A�C�C���b���O���p���p�h�C\n",}) );
                

        setup();
}


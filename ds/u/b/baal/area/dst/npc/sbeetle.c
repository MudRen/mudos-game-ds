inherit NPC;
void create()
{
        set_name("�p����", ({ "small beetle","beetle" }) );
        set("race", "beast");
        set("age", 1);
     set("level",1);

        set("long", "�@���I�W���n�X�ө@�ئⴳ�I���p���ΡC\n");
   set("str",2);
      set("max_hp",8);
    set("dex",-2);
     set("int",1);
       set("con",1);

        set("limbs", ({ "�Y��", "����", "�e��", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 3);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�p���ηn�n�̮̪��b�o�̡㨫�ӡ㨫�h�C\n",
                "�p�����|�_�Ⱖ�X�l�A��ۧA����V�u�سءv�����F��U�A�n���b��A�D�Ԥ@�ˡC\n",}) );
                

        setup();
}


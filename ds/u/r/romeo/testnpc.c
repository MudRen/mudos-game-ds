inherit NPC;

void create()
{
        set_name("�{�����H", ({ "pigking" }) );


        set("level",1);
        set("age", 19);
        set("gender", "�k��");
        set("long",
"�o�ӤH�O�@�ӥǿ����p�ġC\n"
);
        set("chat_chance",70);
        set("chat_msg",({
                (:command("sigh"):),
(:command("sorry"):),
                "�§ʹD�G�u޳�ɡI�藍�_�I�ڿ��F�I�Э�̧ڡI�v\n",
        }) );
        setup();
        add_money("coin", 0);

}


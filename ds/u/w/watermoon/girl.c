inherit NPC;


void create()

{

        set_name("�p����",({ "watermoontoo" }));

        set("long","�o�s�p�����C\n"

);

        set("age", 16);

        set_skill("unarmed", 200);

        set_skill("dodge", 200);

 

        set_temp("apply/dodge", 20);

        set_temp("apply/armor", 20);

 

        set("chat_chance",60);

        set("chat_msg",({

        (: command, "say �A�n�C" :),

        (: command, "smirk" :),

        (: command, "say �ȴP�ὺ�k�O�ڪ��Ѯv���I�I" :),

        (: command, "wink" :),



}));

setup();

        add_money("coin", 100);

}


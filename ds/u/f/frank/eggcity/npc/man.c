inherit NPC;
void create()
{
        set_name("�~��", ({ "man" }) );
        set("long","��b�ೣ�����H�C\n");
        set("level",3+random(5));
        set("age",38+random(10));

        set("combat_exp", 2000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 8);
        set("chat_msg_combat", ({
   (:command("say �̪񤫸̪����A���n�����Ӱ��b!"):),
   (:command("say �{�b�������V�ӶV���F!!"):),
   (:command("say ���ѷ|�U�B!!"):),
   (:command("say ���ѭn��ԣ�O???"):),
   (:command("say ���ѷ|�X�Ӷ�"):),
}));
        set_skill("sword", 20);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);

        setup();
        carry_object(__DIR__"obj/poorcloth")->wear();
       
}


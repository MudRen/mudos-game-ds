inherit NPC;
void create()
{
        set_name("�j�s",({ "bandit" }));
        set("long",
                "�o�å�ݰ_�Ӥ@�Ƥ��ڤڪ��ˤl, �@�ݴN���D���O�n�f,\n"
                "�����D�ǤU�L�h�֥���H������פl�C\n"
        );
        set("age",35+random(6));
	set("attitude", "aggressive");
         set("level",18+random(4));
	set("battlepoint",2);
        set("guild_gifts",({ 7,6,3,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "�j�s���b�n�ۧA�ݡC\n",
  "�j�s��: ��! �ӤF�ӧ䦺���F!\n",
  "�j�s���b�|�B�i���, �����D�b�ݨǤ���C\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "�j�s��: �S�̭�! �W!\n",
  (: command("say �ǩR�� ~~~ !") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        add_money("silver",4);
}

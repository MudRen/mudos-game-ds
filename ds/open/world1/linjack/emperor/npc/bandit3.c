inherit NPC;
void create()
{
        set_name("�C�Τj�~",({ "big bandit","bandit" }));
        set("long",
                "�o�å�ݰ_�Ӥ@�Ƥ����c�٪��ˤl, �@�ݴN���D���O�n�f,\n"
                "�ӥB���L�A�ƭ��Y������, ��A�ӻ������P�ܤj, �ְ{�a..!\n"
        );
        set("age",35+random(6));
	set("attitude", "killer");
        set("level",26+random(4));
	set("battlepoint",2);
        set("guild_gifts",({ 8,6,2,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "�C�Τj�~���b�n�ۧA�ݡC\n",
  "�C�Τj�~��: ��! �ӤF�ӧ䦺���F!\n",
  "�C�Τj�~���G���b���u�ê��u�@�C\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "�C�Τj�~��: �S�̭�! �W!\n",
  (: command("say �ǩR�� ~~~ ! \n") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}

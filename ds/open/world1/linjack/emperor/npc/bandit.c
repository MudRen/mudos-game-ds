inherit NPC;
void create()
{
        set_name("�j�s���o",({ "bandit minion","minion","bandit" }));
        set("long",
                "�o�å�ݰ_�Ӥ@�ƽG�z��, �A��b���H�Q���L����j�s��,\n"
                "�m���m�o����ٯu�����D��C\n"
        );
        set("age",30+random(6));
	set("attitude", "peaceful");
        set("level",10);
	set("battlepoint",1);
	set("evil",3+random(3));
        set("guild_gifts",({ 7,7,3,3 }));
        set("chat_chance",5);
        set("chat_msg",({
  "�j�s���o���b�n�ۧA�ݡC\n",
  "�j�s���o��: �u�}! �u�}!\n",
  "�j�s���o���b�@���H�H������, �@���Ƶ۷m�Ӫ��Ȩ�C\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "�j�s���o��: �A�Q�F����! �¦Y�¶�!?\n",
  (: command("cow") :),
  (: command("angry") :),
}));
        set("wimpy",30);
        setup();
        carry_object(__DIR__"wp/kris")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}

inherit NPC;

void create()
{
	set_name("�p�v", ({"chef"}) );
	set("long", @LONG
    �A���e�o�ӥ��b���檺�p�v�O�ӨӦ�ù�}�۬P��ù���ۤH�A�ڻD
�өʦh�ܡA�@�����e�i���٫ܷũM�A�@������i��N�|½�y�C�L��W
���������ξ��Ӫ��Ӧy�U�A�٬V���F���C
LONG
);
	set("race", "�H��");
	set("age", 40);
	set("level", 19);
        set("attitude","killer");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("eh") :),
       (: command("say �䦺��!?�p�l!?") :),
}));
	setup();
	carry_object(__DIR__"wp/Wp1.c")->wield();
}

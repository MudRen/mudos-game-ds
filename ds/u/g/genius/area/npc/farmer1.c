inherit NPC;

void create()
{
        set_name("�A��",({ "farmer" }) );
        set("long","�@�ӷT�ܭW�y���A�ҡA���G�b�дo����Ʊ��C\n");
        set("race","�H��");
        set("age",36);
        set("level",5);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
         (:command("say �u�Ӧ��A�³��@�~��@�~�h�F�C"):),
         (:command("say �Ѯ�U���A�³��ϦӷU�R�X�ӡC"):),
         (:command("think"):),
         (:command("hmm"):),
        }) );

        set_skill("dodge",12);
        setup();
        add_money("coin",240);           
}

int talk_action()
{
command("hmm");
command("say �A�ܶ����ܡA�N�h������³��a�C");
command("say ��h�@�I�A�ڷ|���A�@�Ǥp�p���y���C");
return 1;}

inherit NPC;

void create()
{
        set_name("�ĤQ�|�N�̤l",({"trainee"}) );
        set("long",@long
�o�O�@�ӸU������~�C�̤l�A�ݰ_�ӴN�O�@�Ƥָg����g�窺�ˤl�C
long
);
        set("age",20);
        set("race","�H��");
        set("level",5);
        set("attitude", "peaceful");
        set("title","�U���");
        set("gender", "�k��" );
        set_skill("axe",20);
        setup();
        carry_object(__DIR__"eq/cloth")->wear();
          carry_object(__DIR__"wp/axe")->wield();
}


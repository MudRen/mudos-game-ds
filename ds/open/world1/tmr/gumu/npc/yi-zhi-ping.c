inherit NPC;

void create()
{
          set_name("���ӥ�",({"yi zhi-ping","yi","ping"}) );
        set("long",
"���ӥ��O�C�B�����j�̤l�A�����u�Ъ��̤l�A�Z�\\�B�H�~���٤����A\n"
"�����u�Ч̤l��������e�~���@��C�u�O�����D����L�|���b�o�̡A������\n"
"��i���۵M�A\n"
);
        set("age",40);
        set("race","�H��");
        set("level",30);
        set("attitude", "peaceful");
        set("title","���u��");
        set("gender", "�k��" );
  
        set_skill("unarmed",80);
        set_skill("sword",80);
        set_skill("quanzhen-sword",80);
        map_skill("sword","quanzhen-sword");

        set("chat_chance",6);
        set("chat_msg",({
                (:command("sigh"):),            
                (:command("walk"):),            
        }) );

        setup();
        carry_object("open/world1/wp/longsword.c")->wield();
          carry_object(__DIR__"obj/cap")->wear();
          carry_object(__DIR__"obj/robe")->wear();

}


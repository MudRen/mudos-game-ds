// sworder.c
    inherit NPC;

    void create()
{set_name("�C��",({"swordsman","man"}) );
set("gender", "�k��");
set("age",34);
set("long", "�L�O�@�ӨӦ۪F�誺�C�ȡA��������ӡA
�]��������h�E�E�E\n");
set("level",250);
set_skill("dodge",100);
set_skill("blade",100);
set_skill("parry",100);
set_skill("block",100);
   setup();
add_money("coin",12000); 
carry_object("/u/m/morral/obj/sorblade.c")->wield();
}

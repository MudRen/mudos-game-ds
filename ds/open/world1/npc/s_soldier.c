inherit NPC;

void create()
{
        set_name("石頭士兵", ({ "stone soldier","soldier" }) );
        set("race","human");
        set("gender", "無性");
        set("level",24);
        set("age",120);
        set("evil",-8);
        set("long",@LONG
巨大的石頭士兵，擁有極強的攻擊力，通常是術士透過符咒
賦予其生命的，也只有施術者能命令它們。
LONG
);
        set_skill("unarmed",90);
        set_skill("fork", 90);
        setup(); 
        carry_object(__DIR__"../wp/belis_spear")->wield();
}


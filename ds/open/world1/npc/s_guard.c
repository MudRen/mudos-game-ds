inherit NPC;

void create()
{
        set_name("守衛石像", ({ "stone guard","guard" }) );
        set("race","human");
        set("level",37);
        set("age",90);
        set("evil",-15);
        set("long",@LONG
由魔法力召喚出來的精靈，附在石頭雕像上面，只聽從召喚
者的命令，永不背叛，召喚者一死亦隨之粉碎。
LONG
);
        set_skill("axe",90);
        set_skill("dodge", 50);
        set_skill("parry", 80);
        setup(); 
        carry_object(__DIR__"../eq/mica_shield")->wear();
        carry_object(__DIR__"../wp/stone_axe")->wield();
}





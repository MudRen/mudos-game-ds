inherit NPC;

void create()
{
        set_name("虎人", ({ "tiger man","man" }) );
        set("race","human");
        set("gender", "男性");
        set("level",34);
        set("age",30);
        set("evil",-15);
        set("long",@LONG
半獸人族中能力最強大的就是虎人，不論是力量、速度，都
凌駕其他種類的半獸人許多，一雙虎爪足以擊斃任何生物。
LONG
);
        setup(); 
        carry_object(__DIR__"../wp/tiger_claw")->wield();
}

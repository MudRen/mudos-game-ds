inherit NPC;

void create()
{
        set_name("黑暗僵屍", ({ "dark zombie","zombie" }) );
        set("race","human");
        set("gender", "男性");
        set("level",35);
        set("age",100);
        set("evil",10);
        set("long",@LONG
僵屍軍團中的中級妖魔，對法術具有強大的抵抗能力，並擁
有黑暗的魔法力保護，十分恐怖。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/b_pants")->wear();
}

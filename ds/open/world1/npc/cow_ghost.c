inherit NPC;

void create()
{
        set_name("���Y��", ({ "cow head ghost","ghost" }) );
        set("race","human");
        set("level",32);
        set("age",300);
        set("evil",-20);
        set("long",@LONG
����a�������t�A�M���޲z�νr���t����A�P�������ú�
�u���Y�����v�C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ghost_plate")->wear();
        carry_object(__DIR__"../wp/purple_hammer")->wield();
}




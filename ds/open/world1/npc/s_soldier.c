inherit NPC;

void create()
{
        set_name("���Y�h�L", ({ "stone soldier","soldier" }) );
        set("race","human");
        set("gender", "�L��");
        set("level",24);
        set("age",120);
        set("evil",-8);
        set("long",@LONG
���j�����Y�h�L�A�֦����j�������O�A�q�`�O�N�h�z�L�ũG
�ᤩ��ͩR���A�]�u���I�N�̯�R�O���̡C
LONG
);
        set_skill("unarmed",90);
        set_skill("fork", 90);
        setup(); 
        carry_object(__DIR__"../wp/belis_spear")->wield();
}


inherit NPC;

void create()
{
        set_name("�u�å۹�", ({ "stone guard","guard" }) );
        set("race","human");
        set("level",37);
        set("age",90);
        set("evil",-15);
        set("long",@LONG
���]�k�O�l��X�Ӫ����F�A���b���Y�J���W���A�uť�q�l��
�̪��R�O�A�ä��I�q�A�l��̤@�����H�����H�C
LONG
);
        set_skill("axe",90);
        set_skill("dodge", 50);
        set_skill("parry", 80);
        setup(); 
        carry_object(__DIR__"../eq/mica_shield")->wear();
        carry_object(__DIR__"../wp/stone_axe")->wield();
}





inherit NPC;

void create()
{
        set_name("��H", ({ "tiger man","man" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",34);
        set("age",30);
        set("evil",-15);
        set("long",@LONG
�b�~�H�ڤ���O�̱j�j���N�O��H�A���׬O�O�q�B�t�סA��
��r��L�������b�~�H�\�h�A�@��������H���ť���ͪ��C
LONG
);
        setup(); 
        carry_object(__DIR__"../wp/tiger_claw")->wield();
}

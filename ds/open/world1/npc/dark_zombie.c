inherit NPC;

void create()
{
        set_name("�·t����", ({ "dark zombie","zombie" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",35);
        set("age",100);
        set("evil",10);
        set("long",@LONG
���ͭx�Τ������ŧ��]�A��k�N�㦳�j�j����ܯ�O�A�þ�
���·t���]�k�O�O�@�A�Q�����ơC
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/b_pants")->wear();
}

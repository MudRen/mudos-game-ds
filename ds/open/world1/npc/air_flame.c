
inherit NPC;

void create()
{
        set_name("�]������", ({ "magic flame","flame" }) );
        set("race","monster");
        set("gender", "�L��");
        set("level",34);
        set("age",0);
        set("evil",5);
        set("long",@LONG
�֦��ͩR�O������ͪ��A�Ⱦa�ۤ@�ӥͩR�֨Ӻ������šA��
�ɳ��Y�b�@�Ӳ��Ҥ��A�u���԰��ɤ~�|�X�ӧ����C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/mf_armor")->wear();
}



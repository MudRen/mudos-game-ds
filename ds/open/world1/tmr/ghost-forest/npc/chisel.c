inherit NPC;

void create()
{
        set_name("����",({"ghost chisel","chisel"}) );
        set("long",@LONG
�@���������H���j���A�����Ф�b�����¦�A�Ⲵ��������A���H��
�n�S���Pı�C
LONG	
	);
        set("race", "���~");    
        set("unit","��");
        set("age",20);
        set("level",20);
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","����" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
	carry_object(__DIR__"obj/meat");
}

// dog.c

inherit NPC;

void create()
{
	set_name("����", ({ "dog" }) );
	set("race", "���~");
	set("age", 3);
     set("level",2);

        set("long", "�@������ż�����������A�ݤF�O�H�ͼ��C\n");
	
   set("str",1);
      set("max_hp",10);
    set("dex",-3);
     set("int",1);
       set("con",1);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�����λ�l�D�F�D�A���}�C\n",
		"�����b�A���}������������M�Q�Q�F��Y�C\n",
		"������ۧA�n�F�n���ڡC\n",
		"�����Ϋ�L��F��ۤv���զ��C\n" }) );
		

       setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "�����a�L�L�s�F�_�ӡC\n", environment());
		return 1;
	}
}

#include <ansi.h>
//updated by alickyuen on 26/12
inherit NPC;
void create()
{
	set_name( "���Ͱʪ�" , ({ "wildanimal" }) );
	set("long",@long
�@�����~�ͬ����p�ʪ��C
long
);
                set("value", 1000);   
	set("age", 60);
	set("level", 10);
 set("race", "���~");
        set("limbs", ({ "�Y��", "����","�ݳ�","�p��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
	setup();
}
int accept_object(object who, object ob)
{
        if( ob->id("food") ) {      //�}��
set("creater",leader);
                set_leader(who);
                message("vision", name() + "�����a��ۧA�s�F�_�ӡC\n", environment());
                return 1;
        }
}

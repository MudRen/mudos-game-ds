#include <ansi.h>
inherit NPC;
void create() 
{ 

 set_name("�}��",({"qu yuan","qo","yuan"}));
 set("age",2302);
 set("gender","�k��");
 set("level",50);
 set("title",HIC"�ѰO�a�a��"NOR);
 set("chat_chance",10);
 set("chat_msg", ({"�}�찪�n�۹D�R���{�{���~�䤼�A�W�üۥG�W�ˡC\n",
                   (:command("sing �e�������L���n"):), 
 }));

 setup();
}

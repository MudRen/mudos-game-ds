#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"�¼�p����"NOR , ({ "small sexking","small","sexking" }) );
        set("long",@long
�@�ӫܥi�R���p�k�͡A��W���ۤ@�|����B�o���H�C
long
);
        set("age", 5);
        set("no_fight",1);
        set("level", 1);
        set("title","����i�R");
        set("gender", "�k��");
        set("race", "�H��");
        set("chat_chance",20);
        set("chat_msg", ({       
name()+"���D: �֨ӹڤۤC�������Z�i���S��^�m�ȣ��C\n",
(: command("smile") :),
(: command("ccc") :),
(: random_move :),
}) );
 setup();
}
void init()
{       
        object ob;
::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob,object bill)
{
  if( !ob || environment(ob) != environment()|| objectp(present("handbills", ob))  ) return;
        switch( random(2) ) {
                case 0:
                        command("say �o��ӭ����f�I�֥h�ݬݹڤۤC�쪺�����a�I");
                        break;
                case 1:
        bill=new(__DIR__"bills");
        bill->move(ob);
message_vision("�¼�p���󵹤F$N�@�i�s�i�ǳ�C\n",ob);
                        command("snicker");
                        break;
        }
}



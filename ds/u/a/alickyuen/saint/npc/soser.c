#include <ansi.h>
//updated by alickyuen 
inherit NPC;
void create()
{
	set_name( "�ŶǤH��" , ({ "sales" }) );
	set("long",@long
�@�ӫŶǤH���A�L���b���o�ǳ椶�зs�}�i���J�|���C
long
);
	set("age", 60);
	set("level", 5);
 set("race", "�H��");
  set("chat_msg", ({       
(:command("hehe"):),  
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
                        command("say �o��ȤH�A�֤@�ǥhSAINT�F�j�󪺳J�|���a�A���}�i�A���ܦh�ڳJ�|���I");
                        break;
                case 1:
        bill=new(__DIR__"obj/handbills");
        bill->move(ob);
message_vision("�ųŤH�����F$N�@�i�ǳ�C\n",ob);
                        command("hehe");
                        break;
        }
}


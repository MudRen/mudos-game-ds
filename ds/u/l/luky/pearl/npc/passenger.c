#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ȫ�", ({ "passenger","�ȫ�","passenger",}));
        set("level",30);
        set("title","[1;33m�~�a�H[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("evil",40);
        set("coin", 1400+random(300));
        set("long", @LONG
�@�Ӻ��y��ת��ȫȡM���b�Q�w��ĵ�ýL�ݵۡC
LONG
        );

//========================�A�����O=================================
   set("attitude", "heroism");    //�^���D�q�� NPC�C

//=============================�۰ʰʧ@=================================
  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�ȫȥΤO����F����@�}!! ���G�D�`�ͮ�..\n",
(:command("say �z�a!! �o�O����A�ȺA�׹�!!!"):),
(:command("say �쩳�n�ڻ��X����~~ �o��}�s�M�O�ڭ��ߨ쪺.."):),
(:command("sigh"):),
(:command("angry"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m�ڥs�����L...�A�ݳo�ӷF����?? �L��!![m
LONG );


//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("chair "+this_player()->query("id")):),
 HIR"�ȫȯ}�f�j�| : �u�i�c���å��T�ڥ����A�T�v\n"NOR,
     }) );

        setup();

//==========================�˳ƹD��=============================
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m�w��ĵ�ð��W���X�ӹ�$N[1;37m��: �Ф��n�ʤ�, �浹�ڭ̳B�z�N�n�F�C[m\n",this_player());
 return 1;
 }
return 0;
}

//======================�ʧ@����======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M�����!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M��������!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say �u���@�I!!�O�Ч�!!");
                break;
        }
}

void reset()
{
        delete("memory");
}

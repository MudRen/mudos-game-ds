#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
        set_name( "����" , ({ "trainman","man" }) );
        set("long",@long
�L�O�@�Ӿr�p�s���D�����q�Ϫ��a�U�K���C�����C�ݨӬ����Q���W�U
�A���y�ɮ᪺�ˤl�C
long
);

        set("age", 50);
        set("level", 5);
	set("gender","�k��");
	set("race","human");
        setup();
        call_out("do_train",60,"train_station",0);
}


void do_train(string arg,int flag)
{
        object ob;
        ob=this_object();
if(flag==0)
{
        command("say �A�̧��n�A�{�b�}���F�C");
        ob->set_temp("do_train",arg);
        ob->move(__DIR__"train");       
        command("say �A�̧��n�A�{�b�}���F�C");
        tell_room(environment(ob),"�������U�@�ӫ��s�A�K���Y�ɶ}�ʡC\n");
        environment(ob)->set("exits",([]) );
        call_out("do_train",20,arg,1);
}
else
{
        message_vision("�A�P�쨮�t�}�l�ܺC�A�ݨӧ֨�F�F�C\n",ob);
        command("say ��F�F�A�j�a�֤U���a�C");
        environment(ob)->set("exits",(["out":__DIR__+arg]) );
        ob->move(__DIR__+arg);
        if(arg=="train_station1") arg="train_station";
        else arg="train_station1";
        call_out("do_train",60,arg,0);

}
        return;
}
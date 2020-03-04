// 1999.12.10 �ק� by Luky
inherit NPC;

void create()
{
	set_name("�ƹL",({"aw-kore","kore"}) );
	set("long",
"�A���e�@�G�A���T�Q�o�쨭�ۥզ�A���զp�ɡA���׽������t�x�k�l\n"
"�ҧl�ަ�A�u���L�@�y�~�{�A���ɦa�Į�A���G��������Ʀb�и��C�Ӭ�\n"
"���n���ݫe�e���C������A�t�����իC���|�u�����C�����^��Q���A��\n"
"����M�A�@���K�o����Z�N�y�ڤ����C\n"
);
	set("age",33);
	set("race","�H��");
	set("level",30);
            set("attitude", "peaceful");
            set("title","�i�Ʊ����j�ĥ|�N�̤l");
           set("gender", "�k��" );
	set("chat_chance",6);
	set("chat_msg",({
	"�ƹL���ۻy�a���D�G�e�Ǥ�l�u���p�ߡA��|��K�p�d�A�H�P�Q�L���d�p����..\n",
	(:command("sigh"):),		
	"�ƹL���ۻy�a���D�G�������F��h�V�p��A�ڭn���M���D��ݩO....\n"
	}) );

      set_skill("unarmed",80);
	set_skill("sword",70);
	set_skill("force",80);
         set_skill("awmay-ken",80);
         map_skill("unarmed","awmay-ken");

	setup();
        carry_object(__DIR__"wp/suisword")->wield();
}
//luky fixed 1999/7/30
int accept_object(object who,object ob)
{
	object pill;

	if(ob->name()!="���P") 	return 0;
	else {
		
	  if(this_object()->query_temp("give_pill")) 
	  {
	    command("say �ڪ����P�w�g��^�ӤF.. ���A�٦��@�����P?");
	    command("? "+who->query("id"));
	    command("say �A�٬O�ۤv�d�ۧa...");
	    return 0;
	  }
	  
      message_vision("$N���F�ƹL�@��$n�C\n",who,ob);
	destruct(ob);
	command("say �o�i�O�ڨ��򥢪����P�I�I�o.....�o...");
	command("thank "+who->query("id"));
	command("say �������w�A�ƬY�L�H�^���A�ƬY���W���X���F���A�N�e�������a�C");
	pill=new(__DIR__"obj/stream");
	pill->move(who);
	pill=new(__DIR__"obj/stream");
	pill->move(who);
	set("chat_msg",({
	"�ƹL���ۻy�a���D�G�٦n�A���P�ש󮳦^�ӤF..\n",
	(:command("idle"):),		
	}) );
	set_temp("give_pill",1);
//	call_out("delay",600,this_object());
	return 1;
	}

}

int talk_action(object me)      //talk �ɷ|���榹�禡.
{
 if(this_object()->query_temp("give_pill")) command("say �p�̱����F��w�g��^�ӤF�A�h�����ߡC");
 else
 {
 	switch(random(3))
 	{
 		case 0:	command("say �аݻդU�i�_���L�@�����P?");
 			break;
 		case 1:	command("say ��.. �@�����O�p�̪������A��b�������~�H�D�C");
 			break;
 		case 2:
 		default:
 			command("say ���򭫭n�����P..��..���ǧڤ@�ɳg�M..");
 			break;
 	}
 }
 return 1;
}


void reset()
{
//	if(!kore) return;
	delete_temp("give_pill");
	set("chat_msg",({
	"�ƹL���ۻy�a���D�G�e�Ǥ�l�u���p�ߡA��|��K�p�d�A�H�P�Q�L���d�p����..\n",
	(:command("sigh"):),		
	"�ƹL���ۻy�a���D�G�������F��h�V�p��A�ڭn���M���D��ݩO....\n"
	}) );
	return;
}

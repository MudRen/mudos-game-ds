// /u/s/shengsan/mob/swimmaster.c	by shengsan  1999.01.27
// ��a�нm �ȥ�


#include <ansi.h>
inherit NPC;
inherit GUILDMASTER;
void randomsay();

void create()
{
	set_name("����",({"yuan","master"}));
	set("gender", "�k��");
	set("long","�®�Q�����L���b�o��C\n");
	set("adv_class",1);		// �]�w�ɮv��¾�~���ĤT��
	set("class","adventurer");	// �Ĥ@��¾�~�� adventurer
	set("no_join",1);
	set("level",20);
	set("age",38);
	set_skill("swim",99);
        set("guild_skills",([	// ����, ����1�i�Ǫ��W��, �W��
		"swimming":({32,3,99}),	// ��a�ޯ�
        ]) );

        set("chat_chance", 50);
        set("chat_msg", ({
	    "�����ּ֦a�b�o��ɨ��j�۵M���®�C\n",
	    "�����b�A���e�վ�F�L�����P�������a�ǡA�����A�n����C\n",
                (:random_move:),
                (: randomsay :),
                (: randomsay :),
        }) );

        set("inquiry/join","���H�ڲ{�b�i�S�����{������A���L�ڭˬO�i�H���I(list)�A�@�U�C");
	set("inquiry/swimming","�٤��|��a�ܡH���A�]�ӻ��o�I");
	set("inquiry/master","�����A�ؼ��F�A�ڤ��O����u�|��S�աA�u�O�@�Ӵ�a�нm�Ӥw�C");

   	setup();

	add_money("coin",30);
}

void randomsay()
{
	switch(random(5)) {
	    case 0 : command("say �аݧA���g��L�ǻ������B��ܡH"); break;
	    case 1 : command("say ��!!�A�n...�ڼ��R��a�A�A�O�H"); break;
	    case 2 : command("say �٤��|��a�ܡH���A�]�ӻ��o�I����(list)�ǳ�C"); break;
	    case 3 : command("snicker"); break;
	    case 4 : command("say �n�[�S����J�h�E�E�F�A�L�i�O�ڦh�~���n�ͳ�C"); break;
	    default : break;
	}

}
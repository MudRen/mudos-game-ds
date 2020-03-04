#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"Obi-Wan"NOR , ({ "obi-wan","wan","obi" }) );
        create_family( HIW "�yJedi Knight�z" NOR ,2,"�Z�h");
        set("level",25);
        set("race","�H��");
        set("age",25);
         set("adv_class",1);
         set("class1",HIW"�yJedi Knight�z"NOR);
        set("gender","�k��");
        set("int",100);
	// �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
	// �ӥB�|�����`�M�n��n���� 20			by shengsan
	set("guild_gifts",({2,3,10,5}));
        set("guild_skills",([
               "dodge" : ({160,2,50}),
               "parry" : ({160,2,50}),
             "sword" : ({160,2,50}),
           "godsword" : ({140,2,50}),
           "meditate" : ({160,2,50}),
           "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-benison" :({180,2,50}),
          ]) );
        set_skill("force", 50);
        set_spell("god-benison",50);
        set_skill("sword", 50);
        set_skill("parry", 50);
           set_skill("dodge",50);
          set_skill("godsword",50);
        set("long",@long
�L�O�yJedi Knight�z���Z�h�A���Ѱ򥻪��ޥ��V�m�C�A�i
�H�ϥ� list�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i�H��
advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ� level���O
�Ӭd�\�һݭn���g��ȡC
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                   (:command("exert mirage-steps"):),
		(:command("cast god-benison"):),
        }) );
        setup();
	carry_object(__DIR__"wp/lightsaber.c")->wield();

}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);	
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
      this_player()->delete("no_check_class");
       return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")==HIW"�yJedi Knight�z"NOR) return notify_fail("�A�w�O�yJedi Knight�z���Z�h�F�C\n");
	 if(arg!="�yJedi Knight�z") return notify_fail("�A�n���J���@�Ӫ���?\n");
            message_vision("����Ż��D�G ��I�ڲ{�b�u��ЧA�@�I"HIW"�yJedi Knight�z"NOR"���򥻧ޯ�C\n",me);
            message_vision("����Ż��D�G  ���~����u����"HIW"�yJedi Knight�z"NOR"�O�q�A�N�n�a�A�ۤv�F�I\n\n",me);
	call_out("domessage",3,me,2);
	return 1;   
}


int domessage(object me,int b)
{
	me=this_player();
  if(b==2)
        message_vision(HIW"����űN�����|�_, $N�����Ǻ����x�_�@�}����........\n\n"NOR,me);	
        else
  if(b==1) 
        message_vision(HIW "�u�����������Y���Y�L���ۼv�������J$N������, $N�P������R���F�@�د����O�q�C\n\n" NOR,me);
        else 
  if(b==0)
                  {
        me->set("adv_class",1);
        me->set("class1",HIW"�yJedi Knight�z"NOR);
        me->create_family(HIW"�yJedi Knight�z"NOR,3,"�Z�h");
        message_vision("$N��������"HIW"�yJedi Knight�z"NOR"���ĤT�N�Z�h�I\n",me);
	return 1;
	}
b--;
call_out("domessage",3,me,b);
} 

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
	if(me->query("class1")=="�yJedi Knight�z" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("�A���O"HIW"�yJedi Knight�z"NOR"���̤l�C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}

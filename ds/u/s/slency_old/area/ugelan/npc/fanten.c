#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����" , ({ "fanten" }) );
        create_family( HIW "�y ILLUSION RISER �z" NOR ,2,"�D��");
        set("level",50);
        set("race","�H��");
        set("age",80);
         set("adv_class",1);
         set("class1",HIW"�y ILLUSION RISER �z"NOR);
        set("gender","�k��");
        set("int",100);
	// �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
	// �ӥB�|�����`�M�n��n���� 20			by shengsan
	set("guild_gifts",({2,3,10,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
             "sword" : ({160,2,60}),
           "godsword" : ({140,2,70}),
           "meditate" : ({160,2,20}),
           "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-fire" : ({170,2,60}),
                "god-benison" :({180,2,30}),
          ]) );
        set_skill("force", 100);
        set_spell("god-fire",90);
        set_spell("god-benison",90);
        set_skill("sword", 100);
        set_skill("parry", 100);
           set_skill("dodge",100);
          set_skill("godsword",100);
        set("long",@long
�L�O[1;37m�y ILLUSION RISER �z[2;37;0m���D�СA���Ѱ򥻪��ޥ��V�m�C�A�i
�H�ϥ� list�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i�H��
advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ� level���O
�Ӭd�\�һݭn���g��ȡC
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
          (:command("cast god-fire"):),
          (:command("exert mirage-steps"):),
		(:command("cast god-benison"):),
        }) );
        setup();
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
        me->set("no_check_class",1);	//�Ȯ�
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
//	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")==HIW"�y ILLUSION RISER �z"NOR) return notify_fail("�A�w�O�y ILLUSION RISER �z���k�v�F�C\n");
	 if(arg!="�y ILLUSION RISER �z") return notify_fail("�A�n���J���@�Ӫ���?\n");
            message_vision("�������D�G ��I����, �ݨӧA�O�@�ӭȱo������Ƥl�I\n",me);
            message_vision("�������D�G �n�a�I�ڳo�N���A���{, ���O���|�n���G"HIY"�y ���쨸�t�O�q  ���������@�� �z"NOR"\n\n",me);
	call_out("domessage",3,me,2);
	return 1;   
}


int domessage(object me,int b)
{
	me=this_player();
  if(b==2)
        message_vision(HIW"�����N�����|�_, $N�����Ǻ����x�_�@�}����........\n\n"NOR,me);	
        else
  if(b==1) 
        message_vision(HIW "�u�����������Y���Y�L���ۼv�������J$N������, $N�P��L���κZ�C\n\n" NOR,me);
        else 
  if(b==0)
                  {
        me->set("adv_class",1);
        me->set("class1",HIW"�y ILLUSION RISER �z"NOR);
        me->create_family(HIW"�y ILLUSION RISER �z"NOR,3,"�k�v");
        message_vision("$N��������"HIW"�y ILLUSION RISER �z"NOR"���ĤT�N�k�v�I\n",me);
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
        if (me->query("family/family_name")==HIW"�y ILLUSION RISER �z"NOR) return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O"HIW"�y ILLUSION RISER �z"NOR"���k�v�C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}

#include <npc.h>
#include <ansi.h>

void create()
{
        set_name( "����" , ({ "mei feng","mei","feng"}) );
        set("long",@long
�@�@���ʬ��@�Ӱ��G�����~�k�l�A����L���A���ۤ@���|�V���l����
�@�A��ۤ@��Ǿ�몺��n�A�y�W�ᦳ���Ф���A���W�I�ۭӥ]���A
�ݰ_�Ӥ����O���a�H�A�����ӳo�వ����C
long
);
        set_race("strength");
        set("age", 35 );
        set_attr( "str" , 25 );
        set_skill( "whip" , 120);
        set_skill("dodge" , 100);
        set_skill("parry" , 100);
        set( "title" , "�|�V���@" );
        set("chat_chance", 5 );
        set("chat_msg", ({
			"���ʳ��ۻy�D�G�u�Q����o�r�o������A�̧ڲ{�b�������ٵL�k���A���F�a..�v\n",
			"���ʱ�ۤѪŹĹD�G�u�ڤQ�~�W�m�A���D�u�����F�o�Ӥ���....�v\n",
			(: command("sigh") :),
        }));
        setup();
        set_level( 20 );
        carry_object(__DIR__"obj/silver-whip")->wield();
        carry_object(__DIR__"obj/grey-cloth")->wear();
		carry_object(__DIR__"obj/big-bag");
}

void exchange( object player , object ob )
{
	object item;
    destruct(ob);
	if( objectp( item=present( "_OBJ_ID_GREEN_BELT_" , player) ) ) {
		// �D�¤F��
		command("thank");
	} else {
		// �e§�F��
		command("say �ڱN�o�����Ȥ��᪺�y�a�e���A����§�a�C");
		tell_room( player , "���ʱq�]�������X�@���A��⪺�y�a�e���F" + player->name() + "�C\n" , player);
		tell_object( player ,  "���ʱq�]�������X�@���A��⪺�y�a�e���F�A�C\n" );
		item = new(__DIR__"obj/green-belt");
		if( !item->move(player) )
			item->move( environment(player) );
	}
}

int accept_object(object me, object ob)
{
      if( !ob->id("_MEI_FENG_QUEST_") || is_fighting() )  {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("wa");
       command("say �o�o...�o...�u�O���§A���F�o�Ӥj��...");
       do_chat(({ (: exchange,  me  , ob:) }) );
       return 1;
}

void relay_say(object ob, string arg)
{
        if( arg=="����")  {
              command("hmm");
              return ;
        }
}


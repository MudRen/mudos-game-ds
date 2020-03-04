#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "�L�ǧJ", ({ "jack lin","lin","jack"}));
 set("long",@LONG
�L�N�O�����j�W���|���j�c�H���@, �︹�Y�����R�����L�ǧJ
, �Q����p���L�|�]��L��ӧ@���p, ���L�H�L�����p�R���ʮ�
�o���G�]�Q���q, �A�ݥL�@�yè�b�M�����Ҽ�, ��b�Q����L��
�M�O�̷|�@�ͷN���¹D�H��, �������~, �L�ﳡ�U���Y��A�פ]
�Ϫ��L�����p�T���������F�q���Y�h���a��.
LONG
    );

        set("level",20);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 36);
   	set("attitude", "peaceful");
   	set("sell_list",([   
           __DIR__"eq/shootbow"   :30,
           __DIR__"eq/crossbow"    :40,
         __DIR__"eq/bolt"    : 5,
        __DIR__"eq/bear_bolt"    :10,

      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
(:command("grin"):),
}) );
      setup();
      add_money("dollar", 40);       
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/cloth")->wear();
      carry_object(__DIR__"eq/fur_waist")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
	if(ob->query("id") == "eagle mark")
           {
		if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�L�ǧJ�@�� "+ob->query("name")+"�C\n",who);
             command("fear");
             obj->start_busy(10);
             obj->set_temp("givemark",1);
             destruct(ob);
             call_out("givemark",1,obj);
	return 1;
	   }

}

void givemark()
{
      int i;
      object me,obj,thing,thing2;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givemark");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�L�ǧJ�j�Y�@��, ��D�إ����M�§A��P���ݥh! \n"NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 2:
            command(CYN"say ���D����������ִN��F??."NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 3:
            say(CYN"�L�ǧJ���M�D: ��...�J�M�p��, �b�U��M���d�l�O�ۧU\n"NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 4:
            thing=new(__DIR__"eq/bear_bolt");
            thing->move(obj);
         thing=new(__DIR__"eq/bear_bolt");
         thing->move(obj);
         thing=new(__DIR__"eq/bear_bolt");
         thing->move(obj);
         thing=new(__DIR__"eq/bear_bolt");
         thing->move(obj);
         thing=new(__DIR__"eq/bear_bolt");
         thing->move(obj);
      command("give bolt to "+ me->query("id") );
    command("give bolt to "+ me->query("id") );
    command("give bolt to "+ me->query("id") );
    command("give bolt to "+ me->query("id") );
    command("give bolt to "+ me->query("id") );
            obj->delete_temp("givemark");
            break;
          }
}

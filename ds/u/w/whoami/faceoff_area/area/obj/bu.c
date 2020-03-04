#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�B����",({"bu liu hu","bu","hu"}));
 set("long","�L�O�b�o���l�̳̦n���u�K�C\n");
 set("age",56);
 set("gender","�k��");
 set("level",30);
 set("title",CYN"������n�P"NOR);
 set_skill("parry",100);
 set_skill("dodge",100);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"�B�����ĹD: �̪񳣨S��ԣ���쪺 "+HIG+"�Ƥl"+NOR+" ��?.....\n",
                   (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","�����դU...��..��F��F... "+HIC+"���r"+NOR+""+HIG+"�i���n�S��!\n"NOR);

	set("inquiry/�Ƥl","���]���@�w�n�O�S�w���F��, �u�n����ѤҤ@�w���L�⪱�ӭӧ�ɨ�...:D.\n"NOR);

	set("inquiry/���r","ť���ұ`��..�̪�`�b�����~���L���ݨ�L�@�إ����z�������� "+HIG+"���n��.\n"NOR);

	set("inquiry/���n��","ť�����n�����֩_�Ǥ���! �J���B�X, �J�X�B��! �u�Q���Ӫ���...���L����"+HIG+"�ߩ�"+NOR+"�P�ˤ]�O�_�Ǥ���...\n");

	set("inquiry/�ߩ�","���n���D�o�n���G�������~��l�ަA�N������, �i�����L�⦳�S���o�تF��??\n"NOR);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "shark bone")
        {
           command("hmm "+who->query("id"));
           command("say �o�i�Sԣ���쪺...-.-");
           return 0;
	}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�B�����@�q "+ob->query("name")+"�C\n",who);
             command("jump");
             obj->start_busy(10);
             obj->set_temp("givehelmet",1);
             destruct(ob);
             call_out("givehelmet",1,obj);
return 1;
    	    }

}

void givehelmet()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�B�������Ī��ݵ��T��...�f���s�D: ����! ����!\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 2:
            command(CYN"say ��..." + RANK_D->query_respect(me) + " �A���@��.."NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 3:
            say(CYN"�B�����ਭ���i�ж�....�C\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",3,me);
            break;
          case 4:
            say(CYN"�L�F�@�|�A�Kť��Ф��ǨӤ@�}�s�n : ���F! ���F!\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 5:
            command("say �o�������]���٦ѤҪ��ǧ@���@�F..�Ѥүd�ۤ]�S��..�N���F�A�a!!");
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 6:
            helmet=new(__DIR__"eq/sky_cloth");
            helmet->move(obj);
            command("give cloth to "+ me->query("id") );
            say(HIY"���W���F�@���T�����C\n"NOR);
            obj->delete_temp("givehelmet");
            break;
          }
}


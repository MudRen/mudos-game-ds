#include <path.h>
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "yip hua","hua" }) );
        set("gender", "�k��" );
        set("long",
            "�o�O�@�Ӥ��~���H�A���M���O���~�A���O��������A�N�s�֤k\n"
            "�]�񤣤W�A���O�o����O���J��A��������Ʊ��C\n"
           );
        set("age",30);
        set("level",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                  (:command("sigh"):),
        }));
        set("talk_reply","��A�o�̨S�A���ơA�֧֨��a�I");
        setup();
}
int accept_object(object who, object ob)
{
           int i;
           object me,obj,book;
           me=this_player();
           obj=this_object();
           i=me->query_temp("quest/wine");
           if( ob->name() != "�h��")
           {
             command("say �ڤ��ݭn�o�ӪF��C");
             command("sigh");
             return 0;
           } 
           else {
             if(me->query_temp("quest/wine") < 7)
             {
message_vision("$N���F����@��"+ob->query("name")+"�C\n",me);
destruct(ob);
               call_out("drop",2,obj);
               return 1;
             }
             else {
               destruct(ob);
               say("����ĤF�f�𻡹D�G�n�a�A�ڴN�ݬݧa...\n");
               say("����ݧ��F����A�������G���I���F�C\n");
               say("����O�L�Y�h�N�N�����G�o��j�L�A�·ЧA�^�h��i�L�A�n�L���ߧa�C\n");
               say("�����A���챼�Y�N���F...\n");
               me->set_temp("quest/wine",i+1);
               if(book=me->query_temp("notebook"))
               book->add_quests_note("SadSworder","����Ч���i�����Ц��F�o���ߡC");
               destruct(obj);
               return 1;
             }
           }
}
void drop()
{
int i;
     object me,shawl;
    me=this_player();
i=me->query_temp("quest/wine");
    shawl=new(ACME_PAST+"area/npc/obj/shawl.c");
    say("����ݤ]���ݪ��N�⥦��b�a�W�C\n");
    shawl->move( environment( this_object() ) );
    if(me->query_temp("quest/wine")>4)
    {
      me->set_temp("quest/wine",i+1);
    }

}

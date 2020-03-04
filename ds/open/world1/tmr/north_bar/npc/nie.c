#include <ansi.h>
#include <net/dns.h>
inherit NPC;

int COUNT = 0;

void do_teach();

void create()
{
      set_name("¿����",({"nie priest", "priest", "nie"}) );
        set("long",@LONG
¿�����O���H�A�������v�����A���M�~�֧֤C�Q���A��
�٬O���m�����C¿�����b�_�Z���w�~���n�X�~�F�A�L�b�o��D
�n���u�@�O�n�Ŵ��t�g�A�ѩ�¿�����������O�v���A�AŪ����
�r�����n��@�w�{�סA�~�i�H��L�ǲߡC
LONG       
);
        set("title","�ǹD�h");
        set("age", 60+random(10));
        set("level",1);
        set("gender","�k��");
        set("race","�H��");
        set("no_kill",1);
        set("chat_chance", 15);
        set("chat_msg",({ 
  (: do_teach :),
  (: do_teach :),
  (: command,"yawn" :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
}));
        setup();
    carry_object(__DIR__"obj/bible")->wield();
}

void do_teach()
{
        object ob,*s;
        string *a,arg;
        int j;

         a = ({
                "In the beginning God created the heaven and the earth.",
                                "And the earth was without form, and void;",
                                "And darkness was upon the face of the deep. And the Spirit of God moved upon the face of the waters",
                                "And God said, Let there be light: and there was light.",
                                "And God saw the light, that it was good: and God divided the light from the darkness.",
                                "And God called the light Day, and the darkness he called Night.",
                                "And the evening and the morning were the first day",
                                "And God said, Let there be a firmament in the midst of the waters, and let it divide the waters from the waters.",
                                "And God made the firmament, and divided the waters which were under the firmament from the waters which were above the firmament; and it was so.",
                                "And God called the firmament Heaven. And the evening and the morning were the second day.",
                                "And God said, Let the waters under the heaven be gathered.",
                });

        if( COUNT >= sizeof(a) ) {
                COUNT = 0;
                arg = "���ѥ�����o�A�U�^����";
        }
        else arg = a[COUNT];

        COUNT++;
        message_vision(HIG"$N��D�G"+arg+"\n"NOR,this_object());

        s = all_inventory(environment(this_object() ));

        for(j=0;j<sizeof(s);j++)
        {
                if(s[j]->query_temp("Confucius") )
                {
                        if( s[j]->query_temp("netdead") == 1 ) continue;
                        // �_�u���H������Ū��...add by -Acme-
                        if( s[j]->query_skill("literate", 1) < 100 )
                        ob=present("_BIBLE_BOOK_", s[j]);
                        if( objectp(ob) ) // ���t�g�AŪ�ѮĪG����n
                        {
                                // ���t�g�|��۩�
//                                  message_vision(NOR""+YEL"$N^X^R^U^[^I^@^YD^AG"+arg+"\n"NOR,sj )
                                s[j]->improve_skill("literate", 5 + random( s[j]->query_int()/5 + 10));
                        }
                        else
                                s[j]->improve_skill("literate", random( s[j]->query_int()/9 + 5 ));

                }
        }


        return;
}

void init()
{
        if( this_player()->query_temp("Confucius") )
                this_player()->delete_temp("Confucius");
        add_action("do_sit","sit");
}

int do_sit()
{
        object me;
        me=this_player();

        if( me->query_temp("Confucius"))
          return notify_fail("�A�w���U�ӱM��ť���F�C\n");
        if( me->is_fighting() )
                return notify_fail("�A�����ۥ��[�A�S��ť�ҡI\n");
        if( me->is_ghost() )
                return notify_fail("�����F�A��Ū�����..:P�I\n");
        if( me->is_busy() )
                return notify_fail("�A�����ۡA�S����ť�ҡC\n");
        if( me->query_skill("literate",1) > 100 )
                return notify_fail("�o�̤w�g�S��k�A�ЧA����F�C\n");
                if( me->query_skill("literate",1) < 60 )
              return notify_fail("�AŪ���Ѧr�٤������m�A�L�kť��¿�������ܡC\n");

        if(me->query("class1")=="�ⶳ�x")
                message_vision("$N���F�n�u��������A�o�L�o�L�v�A�b������F�Ӥ��_������l���U�C\n",me);
        else
                message_vision("$N�b�ǧ�F�Ӧ�l���F�U�ӡA�M��Ū�ѡC\n",me);
        me->set_temp("Confucius",1);
        return 1;
}



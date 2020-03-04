#include <ansi.h>
#include <net/dns.h>
inherit NPC;

int COUNT = 0;

void do_teach();

void create()
{
        set_name("���夽",({"song wen gon", "gon","song" }) );
        set("long",
                "�ǻD�b�X�~�e���g��L��ۧU�⪺�@�ӦѮv�A�ҥH�U\n"
                "�a�����H�e�ө۶ҥL�A�L�{�b�b�B�F���@�a�p�p�ѱЮѡA\n"
                "�����t���H�A�����w�٥i�H��L�Ǩ줣�@�˪����ѳ�I\n");
        set("title","�Ѯv");
        set("age", 40+random(10));
        set("level",25);
        set("gender","�k��");
        set("race","�H��");

        set("chat_chance", 10);
        set("chat_msg",({ 
  (: do_teach :),
  (: do_teach :),
  (: command,"yawn" :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
}));
        set("str",30);
        set("no_fight",1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("fogseven",60);
        map_skill("dodge","fogseven");

        set("flurrydodge",1);
        setup();
        carry_object(__DIR__"wp/book.c")->wield();
        carry_object(__DIR__"eq/whiterobe.c")->wear();
}

void do_teach()
{
        object ob,*s;
        string *a,arg;
        int j;

        ob=this_object();

        if( ob->is_fighting() ) return;
        
        //      ���קK�峹�ɮ׷N�~�Q��
        //      �Ч�H�U�{���O�d, ���L���ɮ�, �i�H�����N��r.
        if( file_size(__DIR__"teacher_read.txt") > 0 ) //luky
        {
                a = explode(read_file(__DIR__"teacher_read.txt"),"\n");
        }
        else a = ({
                "���]�鶴�餣�n�C",
                "�K��E���A�O�~�~�H���A����ɸ`�C���A�L�����꺩�A�ɾ�ã�c�ﳷ�C",
                "�ڤQ�K���A�ڤ���ϡC",
                "�R�]�I�I�A�B���G�G�A�N��������C�H���ѤW�A�i�����ӳq���C",
                "�ڤۤC��u�n���A�j�a�@�_���s�i�C",
                "�����h�g�u�H�A�ѫ��F�q�A�N�����C�U���Ѯt�֫H�D�A���P�s�ڦP�C�C",
                "�E��M�^�A�P�~�����A�U�g�����O�C���x�k�h�A�}�Ѥ�ݲM���C",
                "�@�o�@���m�L�U���n�����A�D�n�����~�@��Z�ǦW�a�A���D���h�C",
                "�z����!! �z����!! �ڤۤC��u����A�����n�n���Ӫ��C",
        "�o��ߤF�٤���ı�ܡH",
        "��M�A�����F�����E�ٴ��A�H�~��_��C",
        "�۫�ۨ������A���ɦ��]�������C",
        "���Ѥ��ΤW�ҶܡH",
        "�L�����l�u�A�h���׼Ʈa�C�L�H�����A�ݤ�U�H�F�C",
        "�p��L�D�۶}��A�ϯ���a�߾~�C�X�B�ѫ���G���A�V�Ӥ@�@�O�H�a�C",
        "�o���C���֡A�����O�L���L��A��Ӫ��a�a��᳣���F�ѫ��ݥˤ��a�C",
        "�O�h���U��W�����y�ӡA���઺�����W�O���~�J�f�A�|�Y�X�H�R�Ӫ��C",
        "�v�p�P�_�i�Φ�ܡB�ФC�B���x�B�S�ĥ|���ΪA�A�ߨ��_�ġC",
                });

        if( COUNT >= sizeof(a) )
        {
                COUNT = 0;
                arg = "���ѥ�����o, �U�^����";
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
//                      if( arg!="none" ) message_vision(NOR""+YEL"$N��۩��D�G"+arg+"\n"NOR,s[j] );
//                      if( arg!="none" ) tell_object(s[j],"�Ať�Fť"+this_object()->name()+"�һ����o�@�q�ܡA�ᦳ�F�ѡC\n");
                        if( s[j]->query_skill("literate", 1) < 70 )
                         s[j]->improve_skill("literate", random( s[j]->query_int()/9+5 ));
                }
        }
        return;
}

void init()
{
        if( this_player()->query_temp("Confucius") )
                this_player()->delete_temp("Confucius");
        if( this_player()->query("id") == "phoenix" && !userp(this_player()) )
        {
            command("kick "+this_player()->query("id"));
            this_player()->move("/open/world1/cominging/area/sidestreet3.c");
        } 
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
        if( me->query_skill("literate",1) > 70 )
                return notify_fail("�o�̤w�g�S��k�A�ЧA����F�A�h��n���Ѯv���a��a�C\n");
//      if( me->query_skill("literate",1) < 30 )
//              return notify_fail("�A�]��Ū���Ѧr�٤������m�A�ҥH��ť��������C\n");

        message_vision("$N�b�ǧ�F�Ӧ�l���F�U�ӡA�M��Ū�ѡC\n",me);
        me->set_temp("Confucius",1);
        return 1;
}


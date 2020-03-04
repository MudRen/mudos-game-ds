#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIR"�îѻ�"NOR);

        set("long",@LONG
�o�̬O���éҦ��ѱ������w�b�����Ѯ��y�M�p�G�A�O�ѱ�
�̤l�M�i�H�q�o�̧l���Ǫ��ѡM�p�G�A���O�ѱ��̤l�M�]����
�Q�w�m�M�ѱ����u�ƬO���Y�K���T�A���F��N�O�@�Ӥj�j����
�d�M�A�i�H�h���̧�@��O�O�O
LONG
        );
        set("exits", ([
  "southwest":__DIR__"pill14",
]));
        set("objects", ([
  __DIR__"npc/birdguard" : 2,
]));
        set("item_desc", ([
  "���d":"�̭���F�\\�h���ѡA�A�i�H�j(search)�ݬݦ��S���A�n���O�O�O\n"
]));
        set("no_clean_up",  0);
        set("light", 1);
        setup();
}

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me;
        me = this_player();

        if( arg != "���d" ) return 0;

        if( me->query("class1") == "�ѱ���" ) 
        {
                message_vision(HIY"$N�}�l�b���d�W�j�X�ݦ��S���A�X�ۤv���ѡO�O�O\n"NOR  ,me);
                call_out("searching", 2, me);
        }
        else message_vision(HIY"$N���n�j�ɡA�o�ݨ��ѱ��u�è��F�i�ӡA�u�n�@�}�C\n"NOR  ,me);
        return 1;
}

void searching(object me)
{
        object p;

        if( !me || environment(me) != this_object() ) return;

        if( me->query_skill("literate") < 20  )
        {
                message_vision(HIY"$N��ʯ��Ų���F�U�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/mbook1");
                p->move(this_player());
        }
        else if( me->query_skill("literate") > 19 &&  me->query_skill("literate") < 40 )
        {
                message_vision(HIY"$N�⥻����خ��F�U�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/mbook2");
                p->move(this_player());
        }
        else if( me->query_skill("literate") > 39 &&  me->query_skill("literate") < 60 )
        {
                message_vision(HIY"$N���Ĩ害�F�U�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/mbook3");
                p->move(this_player());
        }
        else if( me->query_skill("literate") > 59 &&  me->query_skill("literate") < 80 )
        {
                message_vision(HIY"$N�⯫�A�����F�U�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/mbook4");
                p->move(this_player());
        }
        else if( me->query_skill("literate") > 79 &&  me->query_skill("literate") < 100 )
        {
                message_vision(HIY"$N��ѱ��Ĩ害�F�U�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/mbook5");
                p->move(this_player());
        }
        else if( me->query_skill("literate") == 100  )
                message_vision(HIY"$N�w�g�L�k�A���󰪶��Ū��ѤF�C\n"NOR, me);
        return;
}



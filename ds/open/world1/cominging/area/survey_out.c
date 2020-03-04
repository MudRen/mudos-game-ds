#include <ansi.h>

inherit ROOM;

string show_songs();

void create()
{
        set("short", "�B�F������ĥx");
        set("long",@LONG
�A�����b�B�F��������ĥx�W�A�b�o�̪��P��O�Ѧˤ�ҿv����
�A�ݰ_�����M�e���˶�A������ĥx�]�s�b�W�ʦ~���ɶ��F�C�b�A��
�e���y����Ī��ɹ��A�ǻ��p�G�A�j���F�C���]���]�A�A�N��b�o��
�۴�(evoke phoenix)�X����ĨӨ�o�ӥ@�ɤW�A��ɬO�֬O�סA��
���S���H�i�H�w�ơC
LONG
        );
        set("exits", ([
  "enter" : __DIR__"survey.c",
]));

        set("objects",([
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init() {
        add_action("do_evoke","evoke");
}

int do_evoke(string arg) {
        object me, ob, mob;
        int ct = 0;
        if(arg != "phoenix") return 0;
        me = this_player();

        // lv 31 �H�U����s�����
        if( me->query("level") < 31 ) 
                return notify_fail("�A�����Ŧܤ֭n31�šA�~��۳����ġC\n");

        foreach(ob in all_inventory(me))  {
                if( ob->query("phoenix") ) 
                ct++;
        }
        if(ct<7) return notify_fail("�A�S���j����C���]���]�C\n");

        
        if( sizeof(filter_array( children(__DIR__"phoenix"), (: clonep :) )) ) {
                tell_object(me, HIR"�I�s����ĥ��ѡI�лPAlickyuen�p���C\n"NOR);
                return 1;
        }

         mob = new("/open/world1/alickyuen/phoenix/phoenix");
         if( mob->move("/open/world1/cominging/area/boo-lin") )
         {
                message("world:world1:vision", HIB"\n��M�����ѤW�Q���K�G....\n\n\t"HIW"��ӬO"+me->name()+"���\\����C���]���]���"HIR"�����"HIW"�I\n\n"NOR, users());
                me->add("popularity", 1);
                me->add("exp", 3000);
                me->set_temp("no_quit", 1);
                tell_object(me, HIY"�A�o��F1�I�n���3000�g��ȡC\n"NOR);
                log_file("area/phoenix", me->name(1)+"("+me->query("id")+") �� "+ctime(time())+" �I�sphoenix�C\n");
                foreach(ob in all_inventory(me))  {
                       if( ob->query("phoenix") )
                        destruct(ob);
                }
        }
    return 1;
}


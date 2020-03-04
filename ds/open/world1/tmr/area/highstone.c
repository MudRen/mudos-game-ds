// Room: /u/t/tmr/area/highstone.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�j�۶��W");
        set("long", @LONG
�@�����䥭�Z���۶��W�A�O�ӳ����ԫ˪��a��A�u���@�s�p����
���B���ӴH�A�b���a�ݤ[�F�A������ı���N�F�_�ӡC�Q�U�h���M�䤣
�������A�ݨӥu�ണ�_�i��и��U�h�F�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "�p����" : "�X��R�����O�B�Y�Y�V�a�����]�A�b�Ӷ����U�A���o�X�_�S�����~..?\n"
]));
        set("exits", ([ /* sizeof() == 1 */
]));
        set("outdoors","heat");
        set("no_clean_up", 0);

        setup();
}

void do_clear() {
           set("search",0);
}

void init()
{
        add_action("do_search","search");
       add_action("do_jump","jump");
}


int do_search(string arg)
{


        object p;
                object me;
        me=this_player();
 
       if (arg != "�p����") return 0;

        message_vision("$N�����b�p����襤�J�ӥJ�Ӫ��j�M...\n"  ,me);

        if( !query("search") ){
           message_vision("��F�S��A$N�ש�b�p�������@�����P�I�I\n" ,me);
           set("search",1);
           p=new(__DIR__"npc/obj/plate");
           p->move(this_player());
           call_out("do_clear",600);
        } else  {
                message_vision("��F�S��A�רs�@�L����...\n",me);
        }                               
        return 1;
}

int do_jump(string arg)
{
        object me;
        me=this_player();
 
       if (arg != "down") return 0;

        message_vision("$N�L�@�����A�`�l�@�f��A�Ⲵ�@���A���F�U�h...\n",me);
        me->move(__DIR__"arbour");
      tell_room(environment(me),"�Aı�o���e�@�}���T�A"+me->query("name")+"���M�X�{�b�A���e�C\n",me);
        return 1;
}


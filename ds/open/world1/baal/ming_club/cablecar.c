#include <ansi.h>
#include <path.h>
int ming(object me);

inherit ROOM;

void create()
{
 set("short", "���ЦQ�������B");
 set("long", @LONG

(����CCKK,RICHAN���Ѹ�Ƥ�)

LONG
        );
        set("outdoors","land");
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south" : "/open/world1/tmr/bagi/rift",
"up": __DIR__"lighttop",
 ]));
 set("no_clean_up", 0);
        setup();
}

void init()
{
        ::init();
        ming(this_player());
}

int ming(object me)
{
   object ob;
   if(!userp(me)) // for mob. �קK�O�����۳�ͪ��i�J.
   {
        if(ob=me->query("creater"))
        {
                if( !objectp(present("Plate of Holy Fire",ob)) )
                {
                        message_vision("�D�ڱ���,�u, $N�C\n"NOR,ob);
                        me->move("/open/world1/tmr/bagi/rift.c");
                        tell_room(environment(me),me->name()+"�Q���Цu�äF�X�ӡC\n",({ me }));
                        return 1;
                }
        }
   }
    else
   {
        if( !objectp(present("Plate of Holy Fire",me)) && me->query("club/name")!="����" )
        {
        message_vision(HIW"���Ъ��u�è�$N���O���Ъ��Ю{�A�ߧY�N$N�e�ܵ�W�C\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"�Q���Цu�å�F�X�ӡC\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("killer") )
        {
                message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�����F�H�ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"�Q�k�J���|�i�O�Q���F�X�ӡC\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("invader") )
        {
                message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�������L�d���a, �ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"�Q�k�J���|�i�O�Q���F�X�ӡC\n",({ me }));
                return 1;
        }
        return 1;
   }   
}

